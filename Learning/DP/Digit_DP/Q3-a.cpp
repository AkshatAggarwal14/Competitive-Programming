// https://www.spoj.com/problems/PR003004/

// Count numbers between L and R, which have sum of digits = X
// Find sum of digits for all X >= 1 and X <= 135

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    dp[N][X][1] = count of numbers with N digits, and X sum, and under a tight condition
*/

ll dp[17][145][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    function<ll(string&, ll, ll, ll)> dfs = [&](string& num, ll digs, ll sum, bool tight) {
        if (sum < 0) return 0LL;
        if (digs == 0) {
            if (sum == 0) return 1LL;
            return 0LL;
        }

        int ub = ((tight) ? num[ll(num.size()) - digs] - '0' : 9);
        ll& ans = dp[digs][sum][tight];
        if (ans != -1) return ans;

        ans = 0;
        for (int dig = 0; dig <= ub; ++dig) {
            // tight stays 1 in upperbound case only
            ans += dfs(num, digs - 1, sum - dig, tight && (dig == ub));
        }
        return ans;
    };

    auto get_count = [&](ll number) {
        if (number < 0) number = 0;
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        vector<ll> cnt(136);
        for (ll i = 1; i <= 135; ++i) cnt[i] = dfs(s, ll(s.size()), i, 1);  // tight condition
        return cnt;
    };

    ll t;
    cin >> t;
    while (t--) {
        ll L, R;
        cin >> L >> R;
        ll ans = 0;
        auto x1 = get_count(R);
        auto x2 = get_count(L - 1);
        for (ll i = 1; i <= 135; ++i)
            ans += i * ((x1[i] - x2[i]));
        cout << ans << '\n';
    }
}