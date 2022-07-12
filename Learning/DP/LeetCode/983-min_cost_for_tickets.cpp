#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        bitset<366> mark;
        vector<int> dp(366, INF);
        dp[0] = 0;
        for (int& i : days) mark[i] = true;
        for (int i = 1; i <= 365; ++i) {
            if (mark[i]) {
                // if costs[1] lower can use 7 day pass instead of 1
                dp[i] = min(dp[i], dp[i - 1] + costs[0]);
                dp[i] = min(dp[i], dp[max(i - 7, 0)] + costs[1]);
                dp[i] = min(dp[i], dp[max(i - 30, 0)] + costs[2]);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[365];
    }
};