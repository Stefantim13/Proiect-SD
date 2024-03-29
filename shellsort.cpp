#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.in");

vector<long double> v;

void shellsort(long long n, vector<long double> &v)
{
  long long gap, i, j, temp;
  for (gap = n >> 1; gap >= 1; gap >>= 1)
  {
    for (i = gap; i < n; ++i)
    {
      temp = v[i];
      for (j = i; (j >= gap) && (v[j - gap] > temp); j -= gap)
        v[j] = v[j - gap];
      v[j] = temp;
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

      v.resize(n + 1);
      for (int i = 0; i < n; i++)
      {
        fin >> v[i];
        if (v[i] < 0)
          throw invalid_argument("Negative numbers not allowed!");
      }

      shellsort(n, v);
      for (int i = 1; i < n; i++)
      {
        if (v[i] < v[i - 1])
          throw invalid_argument("Sorting didn't work!");
      }
    }
  }
  catch (const exception &e)
  {
    cout << "Exception " << e.what() << endl;
    return 0;
  }
}
