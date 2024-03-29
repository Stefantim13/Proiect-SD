#include <bits/stdc++.h>
using namespace std;
#define INPUT_FILE "input.in"

ifstream fin(INPUT_FILE);

const int B = 1 << 16;
vector<long long> v, w;

void count_sort(long long p, long long n)
{
    vector<int> c(B + 5), d(B + 5);
    for (int i = 0; i < n; ++i)
        c[v[i] / p % B]++;

    for (int i = 1; i < B; ++i)
        d[i] = d[i - 1] + c[i - 1];

    for (int i = 0; i < n; ++i)
    {
        w[d[v[i] / p % B]] = v[i];
        d[v[i] / p % B]++;
    }

    for (int i = 0; i < n; ++i)
        v[i] = w[i];
}

void radix_sort(long long n)
{
    long long maxim = 0;
    for (int i = 0; i < n; ++i)
        maxim = max(maxim, v[i]);

    for (long long i = 1; i <= maxim; i = i * B)
        count_sort(i, n);
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
            w.resize(n + 1);
            for (int i = 0; i < n; i++)
            {
                fin >> v[i];
                if (v[i] < 0)
                    throw invalid_argument("Negative numbers not allowed!");
            }

            radix_sort(n);
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
