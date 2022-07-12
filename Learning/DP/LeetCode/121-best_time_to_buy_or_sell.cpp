#include <bits/stdc++.h>
using namespace std;

// choose one day to buy stock and one day in future to sell it:
// Not even explicit dp
// selling on ith day, buying on [1..i - 1]
// dp[i] = max{price[i] - price[j]}, j from 1 to i - 1
// dp[i] = price[i] - min{price[j]}, j from 1 to i - 1
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int cheapest = int(1e4 + 1);
        for (int& i : prices) {
            cheapest = min(cheapest, i);
            ans = max(ans, i - cheapest);
        }
        return ans;
    }
};
