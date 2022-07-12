#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
   public:
    int minSteps(int n) {
        // dp[i]: minimum steps to reach i A's
        vector<int> dp(n + 1, INF);
        dp[0] = dp[1] = 0;
        for (int k = 2; k <= n; k++) {
            for (int i = 1; i < k; i++) {
                if (k % i != 0) continue;
                dp[k] = min(dp[k], dp[i] + k / i);
            }
        }
        return dp[n];
    }
};

/*
non DP Solution:

const int INF = 1e9;

class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        int t = n;
        for (int d = 2; d * d <= n; d++) {
            while (t % d == 0) {
                s += d;
                t /= d;
            }
        }
        if (t > 1) s += t;
        return s;
    }
};
*/