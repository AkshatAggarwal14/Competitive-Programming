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
const ll MOD = 1e9 + 7;  // 998244353

const int N = 1e6 + 10;
const int M = 1e3 + 5;

void easy() {
    string s;
    cin >> s;
    ll n = sz(s);
    set<char> st;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (st.count(s[i])) {
            ans += 2;
            st.clear();
        } else {
            st.insert(s[i]);
        }
    }
    cout << n - ans << '\n';
}

void test() {
    string s;
    cin >> s;
    ll n = sz(s);
    s = " " + s;
    vector<ll> dp(n + 1), pr(n + 1);
    vector<set<ll>> st(26);
    for (ll i = 1; i <= n; ++i) {
        st[s[i] - 'a'].insert(i);
        dp[i] = pr[i] = 0;
    }
    for (ll i = 1; i <= n; ++i) {
        pr[i] = max(pr[i - 1], dp[i]);
        auto it = st[s[i] - 'a'].upper_bound(i);
        if (it == st[s[i] - 'a'].end()) continue;
        ll j = *it;
        dp[j] = max(dp[j], pr[i - 1] + 1);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << n - (ans * 2) << "\n";
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
        easy();
    }
    return 0;
}
