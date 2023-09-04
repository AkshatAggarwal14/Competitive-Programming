// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dp[10][20][20][2][2];

    int numberOfBeautifulIntegers(int low, int high, int K) {
        auto dfs = [&](const auto &self, const string &s, int i, int evenCnt, int oddCnt, int prevRem, bool tight, bool leading, int &k) {
            if (i == int(s.size())) {
                if (evenCnt == oddCnt and prevRem == 0) return 1;
                return 0;
            }

            int &ans = dp[i][evenCnt - oddCnt + 10][prevRem][tight][leading];
            if (ans != -1) return ans;
            ans = 0;

            int ub = 9;
            if (tight) ub = int(s[i] - '0');
            for (int dig = 0; dig <= ub; ++dig) {
                ans += self(self,
                            s,
                            i + 1,
                            evenCnt + ((!leading or dig > 0) and dig % 2 == 0),
                            oddCnt + (dig % 2 == 1),
                            (prevRem * 10 + dig) % k,
                            tight && (dig == ub),
                            leading and (dig == 0),
                            k);
            }

            return ans;
        };

        auto get_count = [&](int n, int k) {
            memset(dp, -1, sizeof(dp));
            string s = to_string(n);
            return dfs(dfs, s, 0, 0, 0, 0, true, true, k);
        };

        return get_count(high, K) - get_count(low - 1, K);
    }
};

int main() {
    Solution s;
    cout << s.numberOfBeautifulIntegers(10, 20, 3) << '\n';
    cout << s.numberOfBeautifulIntegers(1, 10, 1) << '\n';
    cout << s.numberOfBeautifulIntegers(5, 5, 2) << '\n';
}