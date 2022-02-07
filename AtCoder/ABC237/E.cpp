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
    // opposite to dijkstra
    ll n, m;
    cin >> n >> m;
    vector<ll> H(n);
    for (ll &h : H) cin >> h;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0, u, v, w1, w2; i < m; ++i) {
        cin >> u >> v, --u, --v;
        if (H[u] > H[v]) {
            w1 = H[u] - H[v];
            w2 = -2 * (H[u] - H[v]);
        } else if (H[v] > H[u]) {
            w2 = H[v] - H[u];
            w1 = -2 * (H[v] - H[u]);
        } else {
            w1 = w2 = 0;
        }
        g[u].push_back({v, w1});
        g[v].push_back({u, w2});
    }
    const ll INF = 1e15;
    vector<ll> d(n, -INF);
    d[0] = 0;
    set<pair<ll, ll>> s;  //{happiness, node}
    s.insert({0, 0});
    while (!s.empty()) {
        ll happy = s.rbegin()->first;
        ll parent = s.rbegin()->second;
        s.erase(*s.rbegin());
        for (pair<ll, ll> &child : g[parent]) {
            ll newDis = happy + child.second;
            ll newVer = child.first;
            if (newDis > d[newVer]) {
                s.erase({d[newVer], newVer});
                d[newVer] = newDis;  // update
                s.insert({d[newVer], newVer});
            }
        }
    }
    dbg(g, d);
    cout << *max_element(all(d)) << '\n';
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