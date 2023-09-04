// Count numbers between L and R, which have sum of digits = X

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    dp[N][X][1] = count of numbers with N digits, and X sum, and under a tight condition
    dp[N][X][0] = .. not under a tight condition

    if R = 5231
    => we can fix first digit = 0, 1, 2, 3, 4 AND not be under any tight condition as we can set further values easily from 0..9
    => if first digit = 5, we are under tight condition and second digit cannot be > 2
    => first digit cant be > 5
*/

ll dp[20][180][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll L, R, X;
    cin >> L >> R >> X;

    function<ll(string&, ll, ll, ll)> dfs = [&](string& num, ll digs, ll sum, bool tight) {
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
            if (sum >= dig)
                ans += dfs(num, digs - 1, sum - dig, tight && (dig == ub));
        }
        return ans;
    };

    auto get_count = [&](ll number) {
        assert(number >= 0);
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        return dfs(s, ll(s.size()), X, 1);  // tight condition active
    };

    cout << get_count(R) - get_count(L - 1) << '\n';
}