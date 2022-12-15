// https://www.spoj.com/problems/PR003004/

// Count numbers between L and R, which have sum of digits = X
// Find sum of digits for all X >= 1 and X <= 135

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[17][2];

// dp[N][tight] = sum of sum of digits of N digit numbers <= R

/**
 * If we fix first dig = 0, we get contribution = 0 * Count_of_5_digit_numbers_starting_with_0
 *                                              = 0 * C(0) = 0
 * AND, now we have to check contribution of other 4 digits, so dp[N - 1, 0]
 * If we fix it 1, we get 1 * C(1)
 * If we fix it 2, we get 2 * C(2)
 * If we fix it 3, we get 3 * C(3) + dp[N - 1, 0]

 * If we fix it 7, we get 7 * C(7) + dp[N - 1, 1]


    Now recurrence is, dp[N, 1] = Sum_(x = 0)_(ub - 1) {x * C(x) + dp[N - 1, 0]} + ub * C(ub) + dp[N - 1, 1]
 */

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    function<ll(string&, ll, ll)> cnt = [&](string& num, ll digs, bool tight) {
        if (!tight) return static_cast<ll>(pow(10, digs));

        if (digs == 0) return 1LL;  // if tight is 1, and num of digs = 0, we generated exactly R, thus 1
        ll numbers = 0;
        int ub = ((tight) ? num[ll(num.size()) - digs] - '0' : 9);
        for (int dig = 0; dig <= ub; ++dig) {
            numbers += cnt(num, digs - 1, tight && (dig == ub));
        }
        return numbers;
    };

    function<ll(string&, ll, ll)> dfs = [&](string& num, ll digs, bool tight) {
        if (digs == 0) return 0LL;  // no digit -> no sum of digits

        ll& ans = dp[digs][tight];
        if (ans != -1) return ans;
        ans = 0;

        int ub = ((tight) ? num[ll(num.size()) - digs] - '0' : 9);
        for (int dig = 0; dig <= ub; ++dig) {
            ans += dig * cnt(num, digs - 1, tight && (dig == ub));
            ans += dfs(num, digs - 1, tight & (dig == ub));
        }
        return ans;
    };

    auto get_count = [&](ll number) {
        if (number < 0) number = 0;
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        return dfs(s, ll(s.size()), 1);
    };

    ll t;
    cin >> t;
    while (t--) {
        ll L, R;
        cin >> L >> R;
        cout << get_count(R) - get_count(L - 1) << '\n';
    }
}