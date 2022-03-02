#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    int n, m;
    cin >> n >> m;
    vector<int> dsu(n + 1, 0);
    vector<int> par(n + 1, 0);
    for (int i = 1; i <= n; i++) par[i] = i;

    auto Find = [&](const auto &go, int u) -> int {
        if (par[u] == u) return u;
        return par[u] = go(go, par[u]);
    };

    auto Merge = [&](int u, int v) -> void {
        u = Find(Find, u);
        v = Find(Find, v);
        if (u == v) return;
        if (u > v)
            par[v] = u;
        else
            par[u] = v;
    };

    set<int> present;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        present.insert(a);
        present.insert(b);
        if (Find(Find, a) != Find(Find, b)) Merge(a, b);
    }

    vector<int> dis(n + 2, 1e7);
    dis[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (present.count(i)) {
            int v = Find(Find, i);
            dis[v] = min(dis[v], dis[i]);
            if (i + 1 <= n && Find(Find, i + 1) != Find(Find, i)) {
                dis[i + 1] = min(dis[i + 1], 1 + dis[i]);
            } else {
                dis[i + 1] = min(dis[i + 1], dis[i]);
            }
        } else {
            dis[i + 1] = min(dis[i + 1], 1 + dis[i]);
        }
    }
    cout << dis[n] << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}