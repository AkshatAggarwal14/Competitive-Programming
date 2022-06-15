#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = int(s.size());
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j] = s[i, j] is palindrome
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (i == j)
                    dp[i][j] = 1;
                else if (j - i == 1)
                    dp[i][j] = int(s[i] == s[j]);
                else if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
            }
        }
        int mx = 0;
        string ans;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                int len = j - i + 1;
                if (dp[i][j]) {
                    if (len > mx) {
                        mx = len;
                        ans = s.substr(i, j - i + 1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution s;
    cout << s.longestPalindrome("babad");
    return 0;
}
