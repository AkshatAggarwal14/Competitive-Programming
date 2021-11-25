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
    // https://cses.fi/problemset/task/1194/
    ll n, k, num, root = 0;
    cin >> n >> k;
    queue<ll> friends;
    vector<ll> d(n, -1), deg(n, 0), d_f(n, -1);
    for (ll i = 0; i < k; ++i) {
        cin >> num;
        --num;
        friends.push(num);
        d_f[num] = 0;
    }
    d[root] = 0;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        ++deg[u], ++deg[v];
        g[u].push_back(v), g[v].push_back(u);
    }
    auto BFS = [&](queue<ll> &bfs, vector<ll> &dd) {
        while (!bfs.empty()) {
            ll parent = bfs.front();
            bfs.pop();
            for (ll &child : g[parent]) {
                if (dd[child] != -1) continue;
                dd[child] = dd[parent] + 1;
                bfs.push(child);
            }
        }
    };
    BFS(friends, d_f);
    queue<ll> t;
    t.push(root);
    BFS(t, d);
    dbg(d, d_f);
    for (ll i = 1; i < n; ++i) {
        if (deg[i] == 1) {
            if (d_f[i] > d[i]) {
                return void(cout << "YES\n");
            }
        }
    }
    cout << "NO\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}