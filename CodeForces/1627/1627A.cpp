#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

/*
if All white then -1, as need 1 B for operation
if cell B, ans 0
if both row and col white ans = 2
else ans = 1
*/
void Solution() {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    r--, c--;
    vector<string> g(n);
    for (auto &GG : g) cin >> GG;
    if (g[r][c] == 'B') return void(cout << "0\n");
    vector<string> check(n, string(m, 'W'));
    if (g == check) return void(cout << "-1\n");
    ll black = 0;
    for (ll i = 0; i < m; ++i) black += (g[r][i] == 'B');
    for (ll i = 0; i < n; ++i) black += (g[i][c] == 'B');
    if (!black) return void(cout << "2\n");
    cout << "1\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}