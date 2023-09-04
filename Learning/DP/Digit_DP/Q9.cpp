// https://codeforces.com/contest/1036/problem/C

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll dp[19][19][2];

ll solve(ll low, ll high) {
    auto dfs = [&](const auto &self, const string &s, ll i, ll nonzero, bool tight) {
        if (i == ll(s.size())) {
            return ll(nonzero <= 3);
        }
        ll ub = 9;
        if (tight) ub = int(s[i] - '0');

        ll &ans = dp[i][nonzero][tight];
        if (ans != -1) return ans;
        ans = 0;

        for (ll dig = 0; dig <= ub; ++dig) {
            ans += self(self, s, i + 1, nonzero + (dig > 0), tight && (dig == ub));
        }

        return ans;
    };

    auto get_count = [&](ll n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return dfs(dfs, s, 0, 0, true);
    };

    return get_count(high) - get_count(low - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }
}