/*
    A string of True(T), False(F), or(|), and(&), xor(^) is given.
    Find number of ways to add brackets to obtain true as a result

    s: T^F&T
    ans: 2 [T^(F&T), (T^F)&T]
*/

// TODO: expr1 operator expr2
//? now if operator is xor, it will only be true if left is true and right is false or right is true and left is false; THUS we also need to know TRUE/FALSE for each segment, so we need another dimension
//* XOR = left_true * right_false + right_true * left_false
//* OR = left_true * right_true + left_false * right_true + left_true * right_false
//* AND = left_true * right_true

#include "Akshat.hpp"
const int INF = INT_MAX;

int32_t main() {
    string s;
    cin >> s;
    int n = int(s.size());
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n, {-1, -1}));
    function<int(int, int, bool)> ways = [&](int i, int j, bool isTrue) {
        if (i > j) return 0;
        int &ans = dp[i][j][isTrue];
        if (ans != -1) return ans;
        if (i == j) {
            if (isTrue)
                return ans = int(s[i] == 'T');
            else
                return ans = int(s[i] == 'F');
        }
        ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2) {
            int lT = ways(i, k - 1, true);
            int lF = ways(i, k - 1, false);
            int rT = ways(k + 1, j, true);
            int rF = ways(k + 1, j, false);
            if (s[k] == '|') {
                if (isTrue)
                    ans += lT * rT + lF * rT + lT * rF;  // make true using OR
                else
                    ans += lF * rF;  // make false using OR
            } else if (s[k] == '&') {
                if (isTrue)
                    ans += lT * rT;
                else
                    ans += lF * rT + lT * rF + lF * rF;
            } else if (s[k] == '^') {
                if (isTrue)
                    ans += lT * rF + rT * lF;
                else
                    ans += lT * rT + rF * lF;
            }
        }
        return ans;
    };
    cout << ways(0, n - 1, true) << '\n';   // ways to make expr true
    cout << ways(0, n - 1, false) << '\n';  // ways to make expr false
    return 0;
}
