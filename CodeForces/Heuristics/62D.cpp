#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0, a, b, c; i < n - 1; ++i) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<ll> d(n + 1, INF);
    ll q, k;
    cin >> q >> k;
    d[k] = 0;
    set<pair<ll, ll>> s;  //{distance, node}
    s.insert({0, k});
    while (!s.empty()) {
        ll dis = s.begin()->first;
        ll vertex = s.begin()->second;
        s.erase(s.begin());
        for (pair<ll, ll> &x : g[vertex]) {
            ll newDis = dis + x.second;
            ll newVer = x.first;
            if (newDis < d[newVer]) {
                s.erase({d[newVer], newVer});
                d[newVer] = newDis;  // update
                s.insert({d[newVer], newVer});
            }
        }
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        cout << d[x] + d[y] << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
