// https://www.hackerrank.com/contests/codekar-3/challenges/the-game-of-divisors-1/problem

#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll MOD = 1e9 + 7;

const ll N = 1'000'000;
array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, pr.push_back(i);
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

int getPrimes(int n) {
    int res = 0;
    while (spf[n]) {
        int temp = spf[n];
        while (n % temp == 0) {
            n /= temp;
            ++res;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fill();
    int xr = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        xr ^= getPrimes(num);
    }

    cout << (xr == 0 ? "Achintya" : "Mandal");

    return 0;
}
