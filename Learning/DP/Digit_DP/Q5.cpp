// Find count of digit d for numbers in range [L, R]
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[18][19][2][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // we need to handle leading zeroes and we dont need to count zeroes that are leading
    function<ll(string&, ll, ll, ll, bool, bool)> dfs =
        [&](string& num, ll d, ll digs, ll cnt, bool empty, bool tight) {
            if (digs == 0) return cnt;

            ll& ans = dp[digs][cnt][tight][empty];
            if (ans != -1) return ans;
            ans = 0;

            int ub = ((tight) ? num[ll(num.size()) - digs] - '0' : 9);
            for (int dig = 0; dig <= ub; ++dig) {
                if (dig == 0) {
                    if (empty) {
                        ans += dfs(num, d, digs - 1, cnt, 1, tight && (dig == ub));
                    } else {
                        ans += dfs(num, d, digs - 1, cnt + (dig == d), 0, tight && (dig == ub));
                    }
                } else {
                    ans += dfs(num, d, digs - 1, cnt + (dig == d), 0, tight && (dig == ub));
                }
            }
            return ans;
        };

    auto get_count = [&](ll number, ll d) {
        if (number < 0) number = 0;
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        return dfs(s, d, ll(s.size()), 0, 1, 1);  // tight condition active
    };

    ll t;
    cin >> t;
    while (t--) {
        ll L, R, d;
        cin >> L >> R >> d;
        cout << get_count(R, d) - get_count(L - 1, d) << '\n';
    }
}