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

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (!is_prime(sum)) {
        cout << n << '\n';
        for (ll i = 1; i <= n; ++i) cout << i << ' ';
    } else {
        cout << n - 1 << '\n';
        ll id = -1;
        for (ll i = 0; i < n; ++i)
            if (!is_prime(sum - a[i])) id = i + 1;
        for (ll i = 1; i <= n; ++i)
            if (i != id) cout << i << ' ';
    }
    cout << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}