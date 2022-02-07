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

// const ll N = 200010;
// vector<ll> graph[N];
// // vector<ll> cycles[N];
// ll color[N];
// ll par[N];
// ll mark[N];
// ll cyclenumber = 0;
// ll n, m;

// void dfs_cycle(ll u, ll p) {
//     if (color[u] == 2) return;
//     if (color[u] == 1) {
//         cyclenumber++;
//         ll cur = p;
//         mark[cur] = cyclenumber;
//         while (cur != u) {
//             cur = par[cur];
//             mark[cur] = cyclenumber;
//         }
//         return;
//     }
//     par[u] = p;
//     color[u] = 1;
//     for (ll v : graph[u]) {
//         if (v == par[u]) continue;
//         dfs_cycle(v, u);
//     }
//     color[u] = 2;
// }

// ll power(ll x, ll y, ll p) {
//     ll res = 1;
//     x %= p;
//     while (y > 0) {
//         if (y & 1)
//             res = (res * x) % p;
//         y = y >> 1;
//         x = (x * x) % p;
//     }
//     return res;
// }

// void Solution() {
//     cin >> n >> m;
//     for (ll i = 0; i < m; ++i) {
//         ll u, v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }
//     for (ll i = 1; i <= n; ++i) {
//         if (color[i] == 2) continue;  // visited
//         ll siz = cyclenumber;
//         dfs_cycle(i, 0);
//         siz = cyclenumber - siz;
//         // if component not a cycle or more than 1 cycle in a component
//         if (siz != 1) return void(cout << 0 << '\n');
//     }
//     // for (ll i = 1; i <= m; i++)
//     //     if (mark[i] != 0) cycles[mark[i]].push_back(i);  // find all cycles
//     cout << power(2, cyclenumber, 998244353LL) << '\n';
// }

void Better() {
    //! for 1 cycle in each component, just check if number of vertices in component == number of edges
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> vis(n, 0);
    vector<ll> component;
    function<void(ll)> dfs = [&](ll parent) {
        vis[parent] = 1;
        component.push_back(parent);
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            dfs(child);
        }
    };
    ll ans = 1;
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        component.clear();
        dfs(i);
        ll num_edges = 0;
        for (ll &c : component) num_edges += sz(g[c]);
        num_edges /= 2;
        if (num_edges != sz(component)) return void(cout << "0\n");
        ans *= 2;
        ans = ans % 998244353LL;
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
    Better();
    // Solution();
    return 0;
}