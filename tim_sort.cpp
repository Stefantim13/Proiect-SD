#include <bits/stdc++.h>

using namespace std;

#define CHUNK_SIZE 32

ifstream fin("input.in");

vector<long long> v;

void insertionsort(vector<long long> &v, long long l, long long r)
{
  long long i, j, temp;
  for (i = l + 1; i <= r; ++i)
  {
    temp = v[i];
    j = i - 1;
    while (j >= l && v[j] > temp)
    {
      v[j + 1] = v[j];
      --j;
    }
    v[j + 1] = temp;
  }
}

void merge(vector<long long> &v, vector<long long> &left, vector<long long> &right, long long l, long long m, long long r)
{
  long long len1 = m - l + 1, len2 = r - m;

  for (int i = 0; i < len1; i++)
    left[i] = v[l + i];
  for (int i = 0; i < len2; i++)
    right[i] = v[m + 1 + i];
  int i = 0;
  int j = 0;
  int k = l;

  while (i < len1 && j < len2)
  {
    if (left[i] <= right[j])
      v[k++] = left[i++];
    else
      v[k++] = right[j++];
  }

  while (i < len1)
    v[k++] = left[i++];

  while (j < len2)
    v[k++] = right[j++];
}

void timsort(vector<long long> &v, long long n)
{
  vector<long long> lef, rig;
  lef.resize(n + 1);
  rig.resize(n + 1);
  long long i, j;
  for (i = 0; i < n; i += CHUNK_SIZE)
  {
    insertionsort(v, i, min(i + CHUNK_SIZE - 1, n - 1));
  }
  
  for (i = CHUNK_SIZE; i < n; i = i << 1)
  {
    for (j = 0; j < n; j += i << 1)
    {
      long long mid = i + j - 1;
      long long right = min((j + 2 * i - 1), (n - 1));

      if (mid < right)
        merge(v, lef, rig, j, mid, right);
    }
  }
  
}

int main()
{
  try
  {
    long long test, n, val_max, i;
    int number_of_tests;
    fin >> number_of_tests;
    for (int cnt = 0; cnt < number_of_tests; cnt++)
    {
      fin >> n;
      fin >> val_max;
      cout << cnt << " " << n << " " << val_max << "\n";
      if (val_max == LLONG_MAX || n == LLONG_MAX)
        throw invalid_argument("Numbers are too large!");
      v.resize(n + 5);
      
      for (int i = 0; i < n; i++)
      {
        fin >> v[i];
        if (v[i] < 0)
          throw invalid_argument("Negative numbers not allowed!");
      }
      timsort(v, n);

      for (int i = 1; i < n; i++)
      {
        if (v[i] < v[i - 1])
        {
          throw invalid_argument("Sorting didn't work!");
        }
      }
    }
  }
  catch (const exception &e)
  {
    cout << "Exception " << e.what() << endl;
    return 0;
  }
}
