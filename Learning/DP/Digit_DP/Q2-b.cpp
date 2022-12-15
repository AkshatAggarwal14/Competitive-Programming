// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20][2][2][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    function<ll(string&, ll, ll, ll, ll)> dfs = [&](string& num, ll digs, bool even, bool leading, bool tight) {
        if (digs == 0) return 1LL;

        ll& ans = dp[digs][even][leading][tight];
        if (ans != -1) return ans;
        ans = 0;

        vector<int> digits;
        int ub = (tight ? (num[ll(num.size()) - digs] - '0') : 9);

        if (even) {
            // leading is obviously zero, as leading zeroes always before first odd number
            digits = {0, 2, 4, 6, 8};
            for (int& dig : digits) {
                if (dig <= ub) {
                    ans += dfs(num, digs - 1, 0, 0, tight && (ub == dig));
                }
            }
        } else {
            if (leading) {
                ans += dfs(num, digs - 1, 0, 1, 0);
            }
            digits = {1, 3, 5, 7, 9};
            for (int& dig : digits) {
                if (dig <= ub) {
                    ans += dfs(num, digs - 1, 1, 0, tight && (ub == dig));  // even position later
                }
            }
        }
        return ans;
    };

    auto get_count = [&](ll number) {
        assert(number >= 0);
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        return dfs(s, ll(s.size()), 0, 1, 1);
    };

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cout << "Case #" << i << ": ";
        ll L, R;
        cin >> L >> R;
        cout << get_count(R) - get_count(L - 1) << '\n';
    }
}