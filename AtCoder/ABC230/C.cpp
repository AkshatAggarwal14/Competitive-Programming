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
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    vector<vector<char>> grid(q - p + 1, vector<char>(s - r + 1, '.'));
    for (ll k = max(p - a, r - b); k <= min(q - a, s - b); ++k) grid[a + k - p][b + k - r] = '#';
    for (ll k = max(p - a, b - s); k <= min(q - a, b - r); ++k) grid[a + k - p][b - k - r] = '#';
    for (ll i = 0; i < sz(grid); ++i) {
        for (ll j = 0; j < sz(grid[i]); ++j) cout << grid[i][j];
        cout << '\n';
    }
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