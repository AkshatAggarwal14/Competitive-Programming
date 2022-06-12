/*
    Here we have to divide a string into number of substrings, such that each substring is a palindrome.
    Worst case: each character in seperate substring, thus n - 1 partitions

    Example:
    s: anitinb
    partitions: a|nitin|b [Thus 2 partitions]
*/

#include "Akshat.hpp"
const int INF = INT_MAX;

int32_t main() {
    string s;
    cin >> s;
    int n = int(s.size());
    function<bool(int, int)> palindrome = [&](int i, int j) {
        while (i < j)
            if (s[i++] != s[j--]) return false;
        return true;
    };
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> partitions = [&](int i, int j) {
        if (i > j) return 0;
        int &ans = dp[i][j];
        if (ans != -1) return ans;
        if (palindrome(i, j)) return ans = 0;
        ans = INF;
        for (int k = i; k < j; ++k) {
            int temp = partitions(i, k) +      // left partition cost
                       partitions(k + 1, j) +  // right partition cost
                       1;                      // 1 partition between left and right
            ans = min(ans, temp);
        }
        return ans;
    };
    cout << partitions(0, n - 1) << '\n';
    // dbg(dp);
    return 0;
}
