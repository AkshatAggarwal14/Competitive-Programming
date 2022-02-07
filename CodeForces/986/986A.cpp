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

const ll inf = LLONG_MAX;
void Solution() {
    ll n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<vector<ll>> g(n);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i], --a[i];
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    // multisource bfs for all goods of same type
    vector<vector<ll>> dist(k, vector<ll>(n, -1));  // find a cost to bring a good in each town
    for (ll type = 0; type < k; type++) {
        queue<ll> bfs;
        for (ll i = 0; i < n; i++) {
            if (a[i] != type) continue;
            dist[type][i] = 0;
            bfs.push(i);
        }
        while (!bfs.empty()) {
            ll parent = bfs.front();
            bfs.pop();
            for (ll &child : g[parent]) {
                if (dist[type][child] != -1) continue;
                dist[type][child] = dist[type][parent] + 1;
                bfs.push(child);
            }
        }
    }
    vector<ll> d(k);
    for (int i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) d[j] = dist[j][i];
        ranges::sort(d);
        cout << accumulate(d.begin(), d.begin() + s, 0LL) << ' ';
    }
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
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}