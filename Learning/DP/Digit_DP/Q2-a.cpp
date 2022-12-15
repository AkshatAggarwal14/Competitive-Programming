// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    function<ll(string&, ll, ll)> dfs = [&](string& num, ll digs, bool tight) {
        if (digs == 0) return 1LL;

        ll i = ll(num.size()) - digs;
        int ub = ((tight) ? num[i] - '0' : 9);
        ll& ans = dp[digs][tight];
        if (ans != -1) return ans;

        ans = 0;
        for (int dig = 0; dig <= ub; ++dig) {
            if ((i & 1) != (dig & 1)) {  // odd number at even position, even at odd position
                ans += dfs(num, digs - 1, tight && (dig == ub));
            }
        }
        return ans;
    };

    auto get_count = [&](ll number) {
        assert(number >= 0);
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        ll res = dfs(s, ll(s.size()), 1);
        ll digs = max(ll(s.size()) - 1, 0LL);
        ll t = 1;
        while (digs--) {
            t *= 5;
            res += t;
        }
        // above we get [0, 9] + [10, 99] + [100, 999] + [1000, 1345]
        // dp calculates boring numbers in range [1000, 1345] -> no leading zeroes
        return res;
    };

    // this DP calculates boring numbers with digits equal to given number

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cout << "Case #" << i << ": ";
        ll L, R;
        cin >> L >> R;
        cout << get_count(R) - get_count(L - 1) << '\n';
    }
}