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
    ll n, m;
    cin >> n >> m;
    map<ll, set<ll>> mep;
    set<ll> st;
    for (ll i = 1; i <= n; ++i) st.insert(i);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        if (v < u) swap(u, v);
        mep[u].insert(v);
        if (st.find(u) != st.end()) st.erase(u);
    }
    ll q;
    cin >> q;
    while (q--) {
        ll type, u, v;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            if (v < u) swap(u, v);
            mep[u].insert(v);
            if (st.find(u) != st.end()) st.erase(u);
        } else if (type == 2) {
            cin >> u >> v;
            if (v < u) swap(u, v);
            mep[u].erase(v);
            if (sz(mep[u]) == 0) st.insert(u);
        } else
            cout << sz(st) << " \n";
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
