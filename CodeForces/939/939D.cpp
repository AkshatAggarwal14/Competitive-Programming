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
    string a, b;
    cin >> n >> a >> b;
    vector<vector<ll>> g(26);
    vector<ll> vis(26, 0);
    auto dfs = [&](const auto &self, ll ch) -> void {
        vis[ch] = true;
        for (auto &child : g[ch]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };
    vector<array<char, 2>> ans;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == b[i]) continue;
        fill(all(vis), 0LL);
        dfs(dfs, a[i] - 'a');
        if (vis[b[i] - 'a']) continue;
        ans.push_back({a[i], b[i]});
        g[a[i] - 'a'].push_back(b[i] - 'a');
        g[b[i] - 'a'].push_back(a[i] - 'a');
    }
    cout << sz(ans) << '\n';
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
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}