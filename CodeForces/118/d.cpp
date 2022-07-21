#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e8;
int dp[2][12][102][102];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    /*
    dp[0][k][n1][n1] -> if k type 0s at end, having used n1 and n2
    dp[1][k][n1][n2] -> if k type 1s at end, having used n1 and n2
     */

    memset(dp, -1, sizeof(dp));
    function<int(int, int, int, int)> dfs = [&](int used_n1, int used_n2, int consec, int type) {
        if (used_n1 > n1 || used_n2 > n2) return 0;
        if (type == 0 && consec > k1) return 0;
        if (type == 1 && consec > k2) return 0;
        if (used_n1 == n1 && used_n2 == n2) return 1;  //! end

        int &ans = dp[type][consec][used_n1][used_n2];
        if (ans != -1) return ans;
        ans = 0;
        // use type 0:
        if (type == 0)
            (ans += dfs(used_n1 + 1, used_n2, consec + 1, 0)) %= MOD;
        else
            (ans += dfs(used_n1 + 1, used_n2, 1, 0)) %= MOD;
        // use type 1:
        if (type == 1)
            (ans += dfs(used_n1, used_n2 + 1, consec + 1, 1)) %= MOD;
        else
            (ans += dfs(used_n1, used_n2 + 1, 1, 1)) %= MOD;
        return ans;
    };
    cout << dfs(0, 0, 0, 0) << '\n';
}