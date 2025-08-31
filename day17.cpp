/*
  Question :- 
  Given a positive integer N, your task is to find its prime factorization. Return a list of prime numbers that multiply together to give N. 
  If N is prime, the output should be a list containing only N. 
  Prime factorization is the process of breaking down a number into the set of prime numbers that, when multiplied together, result in the original number. 
  For example, if N = 18, its prime factors are [2, 3, 3] because 2×3×3=18.
*/


// Code :- 
#include <bits/stdc++.h>
using namespace std;

vector<long long> primeFactors(long long n) {
    vector<long long> f;
    if (n <= 1) return f;        

    while (n % 2 == 0) {      
        f.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) { 
        while (n % d == 0) {
            f.push_back(d);
            n /= d;
        }
    }
    if (n > 1) f.push_back(n);     
    return f;
}

int main() {
    long long N; 
    cin >> N;
    auto f = primeFactors(N);
    if (f.empty()) cout << "[]\n";
    else {
        cout << "[";
        for (size_t i = 0; i < f.size(); ++i) {
            if (i) cout << ", ";
            cout << f[i];
        }
        cout << "]\n";
    }
    return 0;
}
