#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.in");

vector<long long> v, cop;

void merge_sort(int left, int right)
{
    int med = left + (right - left) / 2;
    int i, j, k;
    if (left < right)
    {
        merge_sort(left, med);
        merge_sort(med + 1, right);
        i = left;
        j = med + 1;
        k = 0;
        while (i <= med && j <= right)
        {
            if (v[i] < v[j])
                cop[k++] = v[i++];
            else
                cop[k++] = v[j++];
        }
        while (i <= med)
            cop[k++] = v[i++];
        while (j <= right)
            cop[k++] = v[j++];
        for (i = left, j = 0; i <= right; ++i, ++j)
            v[i] = cop[j];
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
            cop.resize(n+1);
            for (int i = 0; i < n; i++)
            {
                fin >> v[i];
                if (v[i] < 0)
                    throw invalid_argument("Negative numbers not allowed!");
            }

            merge_sort(0, n - 1);
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
    return 0;
}