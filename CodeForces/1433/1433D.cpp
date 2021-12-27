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

void Solution() {
    ll n;
    cin >> n;
    vector<ll> color(n);
    for (ll &c : color) cin >> c;
    ll root = 1;
    ll other = -1;
    vector<array<ll, 2>> ans;
    for (ll i = 2; i <= n; ++i) {
        if (color[i - 1] == color[root - 1]) continue;
        ans.push_back({root, i});
        other = i;
    }
    // If all are same color, then no, else we set a root
    if (other == -1) return void(cout << "NO\n");
    for (ll i = 2; i <= n; ++i) {
        if (i == other || color[i - 1] != color[root - 1]) continue;
        ans.push_back({other, i});
    }
    cout << "YES\n";
    for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
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