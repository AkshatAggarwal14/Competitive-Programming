// https://leetcode.com/problems/count-special-integers/

#include <bits/stdc++.h>
using namespace std;

int dp[10][2][1 << 10];

int countSpecialNumbers(int n) {
    string s = to_string(n);

    auto dfs = [&](const auto &self, int i, bool tight, int presentMask) {
        if (i == int(s.size())) {
            return int(presentMask > 0);
        }

        int &ans = dp[i][tight][presentMask];
        if (ans != -1) return ans;

        ans = 0;

        int ub = 9;
        if (tight) ub = int(s[i] - '0');

        for (int dig = 0; dig <= ub; ++dig) {
            if ((presentMask >> dig) & 1) continue;
            ans += self(self, i + 1,
                        tight && (ub == dig),
                        (presentMask == 0 and dig == 0) ? (presentMask) : (presentMask | (1 << dig)));
        }

        return ans;
    };

    memset(dp, -1, sizeof(dp));
    return dfs(dfs, 0, true, 0);
}

int main() {
    cout << countSpecialNumbers(20) << '\n';
    cout << countSpecialNumbers(5) << '\n';
}