#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.in");

vector<long long> v;

void heapify(vector<long long> &v, long long n, long long i)
{
  long long largest = i;
  long long left_child = 2 * i + 1, right_child = 2 * i + 2;

  if (left_child < n && v[largest] < v[left_child])
    largest = left_child;
  if (right_child < n && v[largest] < v[right_child])
    largest = right_child;
  if (i != largest)
  {
    swap(v[i], v[largest]);
    heapify(v, n, largest);
  }
}

void heapsort(vector<long long> &v, long long n)
{
  long long i;
  for (i = n / 2 - 1; i >= 0; --i)
    heapify(v, n, i);

  for (i = n - 1; i > 0; --i)
  {
    swap(v[0], v[i]);
    heapify(v, i, 0);
  }
}

int main()
{
  try
  {
    long long n, val_max;
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

      heapsort(v, n);
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
