#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.in");

vector<long double> v;

long long median_of_3(long long low, long long med, long long high, vector<long double> &v)
{
  if ((v[low] > v[med]) ^ (v[low] > v[high]))
  {
    return low;
  }
  else if ((v[med] < v[low]) ^ (v[med] < v[high]))
  {
    return med;
  }
  else
  {
    return high;
  }
}

long long pivot_med_3(long long low, long long high, vector<long double> &v)
{
  long long med = (high + low) / 2;
  long long pos_med_3 = median_of_3(low, med, high, v);
  swap(v[pos_med_3], v[high]);

  long long i, j = low;
  for (i = low; i < high; ++i)
    if (v[i] < v[high])
    {
      swap(v[i], v[j]);
      ++j;
    }
  swap(v[j], v[high]);
  return j;
}


void quicksort(long long low, long long high, vector<long double> &v)
{
  if (low < high)
  {
    long long pi = pivot_med_3(low, high, v);
    quicksort(low, pi - 1, v);
    quicksort(pi + 1, high, v);
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

      quicksort(0, n - 1, v);
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
