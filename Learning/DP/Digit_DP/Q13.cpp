#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2];

int dfs(int i, bool tight, bool leading, const string &s, int num) {
    if (i == int(s.size())) {
        if (leading) {
            return 0;
        }
        cout << num << '\n';
        return 1;
    }
    int &ans = dp[i][tight][leading];
    if (ans != -1) return ans;

    ans = 0;

    int ub = 9;
    if (tight) {
        ub = s[i] - '0';
    }

    if (leading) {
        ans += dfs(i + 1, tight && (ub == 0), true, s, num * 10);
    }
    for (int dig : {1, 2, 3, 4, 5}) {
        if (dig <= ub) {
            ans += dfs(i + 1, tight && (ub == dig), false, s, num * 10 + dig);
        }
    }
    return ans;
}

int countSpecialNumbers(int n) {
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    cout << "\n-----\n";
    return dfs(0, true, true, s, 0);
}

int main() {
    cout << countSpecialNumbers(2);
    cout << countSpecialNumbers(71);
}