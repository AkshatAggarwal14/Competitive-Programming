/**
 *    author:  master._.mind
 *    created: 2022.06.28 18:01:41
 **/

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
    int n, k;
    cin >> n >> k;
    set<pair<ll, ll>> st;
    for (ll i = 1, num; i <= n; ++i) {
        cin >> num;
        st.insert({num, i});
    }
    vector<pair<ll, ll>> ans;
    while (k--) {
        auto it1 = st.begin();
        auto it2 = --st.end();
        ll i = (*it1).first;
        ll j = (*it2).first;
        if (j - i < 2) break;
        ans.push_back({(*it2).second, (*it1).second});
        st.insert({i + 1, (*it1).second});
        st.insert({j - 1, (*it2).second});
        st.erase(it1);
        st.erase(it2);
    }
    auto it1 = st.begin();
    auto it2 = --st.end();
    ll i = (*it1).first;
    ll j = (*it2).first;
    cout << j - i << ' ' << sz(ans) << '\n';
    for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
