#include <bits/stdc++.h>

using namespace std;


int main() {
    srand(time(0));
    ofstream fout ("input.in");
    const int number_of_tests = 1;
    fout << number_of_tests << "\n";
    for (int cnt = 0; cnt < number_of_tests; cnt++) {
        long long n = 5000000 + rand() % 100000;
        long long max_val = 100000000000000;
        fout << n << " " << max_val << "\n";
        for (int i = 0; i < n ; i++) {
            long long x;
            x = rand() % max_val;
            fout << x << " ";
        }
        fout << "\n";
    }
    
    return 0;
}