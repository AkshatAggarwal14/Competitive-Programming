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
    ll n, q, u, v;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    vector<ll> cnt(n + 1, 0);
    while (q--) {
        cin >> u >> v;
        ++cnt[u - 1];
        --cnt[v];
    }
    for (ll i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
    ranges::sort(cnt, greater<ll>()), ranges::sort(a, greater<ll>());
    ll sum = 0;
    for (ll i = 0; i < n; ++i) sum += a[i] * cnt[i];
    cout << sum << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}