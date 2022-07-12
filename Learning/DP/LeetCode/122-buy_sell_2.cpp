#include <bits/stdc++.h>
using namespace std;

// choose one day to buy stock and one day >= curr to sell it, can do multiple times

// buy at valley, sell at peak
class Solution {
   public:
    int maxProfit(vector<int>& P) {
        int ans = 0;
        for (int i = 1; i < size(P); i++)
            if (P[i] > P[i - 1])
                ans += P[i] - P[i - 1];
        return ans;
    }
};