#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, p;
    cin >> n >> p;
    if (n > p) return void(cout << 0 << '\n');  // some remainder repeats so 0
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll res = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            res = (res * abs(a[i] - a[j]) % p);
        }
    }
    cout << res % p;
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}