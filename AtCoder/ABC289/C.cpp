#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
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
    vector<vector<ll>> sets(m);
    for (auto &x : sets) {
        ll k;
        cin >> k;
        x.resize(k);
        for (auto &y : x) cin >> y;
    }
    ll cnt = 0;
    for (ll i = 1; i < (1 << m); ++i) {
        set<ll> st;
        for (ll j = 0; j < m; ++j) {
            if ((1 << j) & i) {
                for (auto &x : sets[j]) st.insert(x);
            }
        }
        if (st.size() == n) ++cnt;
    }
    cout << cnt << '\n';
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
