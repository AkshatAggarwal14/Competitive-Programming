#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    // consecutive elements max & range
    ll n;
    cin >> n;
    vector<ll> a(n), ans(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    ans[0] = (a[0] & a[1]);
    ans[n - 1] = (a[n - 2] & a[n - 1]);
    for (ll i = 1; i < n - 1; ++i) {
        ans[i] = max((a[i - 1] & a[i]), (a[i] & a[i + 1]));
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}