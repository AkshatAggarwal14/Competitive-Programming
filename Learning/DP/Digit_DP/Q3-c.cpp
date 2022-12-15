#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20][180][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    function<ll(string&, ll, ll, ll)> dfs = [&](string& num, ll digs, ll sum, bool tight) {
        if (digs == 0) return sum;

        ll& ans = dp[digs][sum][tight];
        if (ans != -1) return ans;
        ans = 0;

        int ub = ((tight) ? num[ll(num.size()) - digs] - '0' : 9);
        for (int dig = 0; dig <= ub; ++dig) {
            ans += dfs(num, digs - 1, sum + dig, tight && (dig == ub));
        }

        return ans;
    };

    auto get_count = [&](ll number) {
        if (number < 0) number = 0;
        memset(dp, -1, sizeof(dp));
        string s = to_string(number);
        return dfs(s, ll(s.size()), 0, 1);  // tight condition active
    };

    ll t;
    cin >> t;
    while (t--) {
        ll L, R;
        cin >> L >> R;
        cout << get_count(R) - get_count(L - 1) << '\n';
    }
}