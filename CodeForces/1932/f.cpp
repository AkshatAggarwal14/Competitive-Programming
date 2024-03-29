#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
// const ll N = 1e6 + 15;
// const ll N = 15;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> segs(m);
    map<ll, vector<ll>> add, sub;

    for (ll i = 0; i < m; ++i) {
        cin >> segs[i].first >> segs[i].second;
        sub[segs[i].first].push_back(segs[i].second);
        add[segs[i].second].push_back(segs[i].second);
    }

    vector<ll> farthest(n + 20, -1);
    vector<ll> passing(n + 20, 0);
    multiset<ll> st;
    for (ll i = n + 20 - 1; i >= 0; --i) {
        for (auto &x : add[i]) {
            st.insert(x);
        }

        // currently active
        if (!st.empty()) {
            farthest[i] = *(st.rbegin());
            passing[i] = st.size();
        }

        for (auto &x : sub[i]) {
            st.erase(st.find(x));
        }
    }

    vector<ll> dp(n + 20, 0);

    for (ll i = n + 20 - 2; i >= 0; --i) {
        dp[i] = dp[i + 1];
        if (passing[i])
            dp[i] = max(dp[i + 1], passing[i] + dp[farthest[i] + 1]);
    }

    cout << dp[0] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
