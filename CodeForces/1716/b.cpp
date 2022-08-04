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
    vector<ll> p(n);
    iota(all(p), 1);
    vector<vector<ll>> ans;
    map<ll, ll> st;
    for (ll rot = 0; rot < n; ++rot) {
        auto b = p;
        rotate(b.begin() + rot, b.begin() + rot + 1, b.end());
        dbg(b);
        ll res = 0;
        for (ll i = 0; i < n; ++i) res += (b[i] == i + 1);
        if (st.count(res)) continue;
        st[res] = rot;
        ans.push_back(b);
    }
    cout << sz(st) << '\n';
    for (auto it = st.rbegin(); it != st.rend(); ++it) {
        ll id = it->second;
        for (auto &x : ans[id]) {
            cout << x << ' ';
        }
        cout << '\n';
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
