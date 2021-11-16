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
    ll n;
    cin >> n;
    map<ll, ll> deg;  // need maps as the numbers are large
    map<ll, vector<ll>> g;
    for (ll i = 0; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
        g[u].push_back(v), g[v].push_back(u);
    }
    ll st = 0;
    for (auto &[x, y] : deg)
        if (y == 1) st = x;  // start with degree 1
    function<void(ll, ll)> dfs = [&](ll node, ll parent) {
        cout << node << ' ';
        for (auto &child : g[node]) {
            if (child == parent) continue;
            dfs(child, node);
        }
    };
    dfs(st, -1);
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