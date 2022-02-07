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
    // Gather in 1st cell, then go through entire board in zigzag
    /*
        (n - 1) + (m - 1) + n * (m - 1) + (n - 1) <- going down
        n + m + nm - 3 <= 2nm
        n + m - 3 <= nm
        n + m - 1 - nm - 2 <= 0
        nm - n - m + 1 + 2 >= 0
        (n - 1) * (m - 1) + 2 >= 0
        !! Always true
    */
    ll n, m, k, x, y;
    cin >> n >> m >> k;
    for (ll i = 0; i < k; ++i) cin >> x >> y;
    for (ll i = 0; i < k; ++i) cin >> x >> y;
    string L(m - 1, 'L'), R(m - 1, 'R');
    string ans(string(n - 1, 'U') + L);  // to 1st cell
    for (ll i = 0; i < n; ++i) {
        if (i % 2 == 0) ans += R;
        if (i % 2) ans += L;
        if (i != n - 1) ans += 'D';
    }
    cout << sz(ans) << '\n';
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