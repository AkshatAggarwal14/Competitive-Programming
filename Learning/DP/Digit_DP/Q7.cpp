// https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][20][2][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    function<ll(string&, ll, ll, ll, ll)> dfs = [&](string& num, ll digs, ll last, bool leading, bool tight) {
        if (digs == 0) return 1LL;

        ll& ans = dp[digs][last][leading][tight];
        if (ans != -1) return ans;
        ans = 0;

        int ub = (tight ? (num[ll(num.size()) - digs] - '0') : 9);
        if (leading) {
            ans += dfs(num, digs - 1, -1, true, false);
            for (int dig = 1; dig <= ub; ++dig) {
                if (dig != last)
                    ans += dfs(num, digs - 1, dig, false, tight && (ub == dig));
            }
        } else {
            for (int dig = 0; dig <= ub; ++dig) {
                if (dig != last)
                    ans += dfs(num, digs - 1, dig, false, tight && (ub == dig));
            }
        }

        return ans;
    };

    auto get_count = [&](ll number) {
        if (number < 0) return 0LL;
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        return dfs(s, ll(s.size()), -1, true, true);
    };

    ll L, R;
    cin >> L >> R;
    cout << get_count(R) - get_count(L - 1) << '\n';
}