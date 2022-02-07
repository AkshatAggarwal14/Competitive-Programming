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
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

void Solution() {
    ll n, l, r, x, ans = 0;
    cin >> n >> l >> r >> x;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) cin >> c[i];
    for (uint64_t mask = 0; mask < (1ULL << n); ++mask) {
        if (popcount(mask) < 2) continue;
        ll total = 0, mx = -1, mn = LLONG_MAX;
        for (ll i = 0; i < n; ++i) {
            uint64_t bit = (1LL << i) & mask;
            if (!bit) continue;
            total += c[i];
            amax(mx, c[i]);
            amin(mn, c[i]);
        }
        if (total >= l && total <= r && mx - mn >= x) ans++;
    }
    cout << ans << '\n';
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
    return 0;
}