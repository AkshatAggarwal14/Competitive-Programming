#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

class Solution {
   public:
    int longestStrChain(vector<string> &words) {
        int n = int(words.size());
        vector<int> dp(n, -1);
        map<string, int> idx;
        for (int i = 0; i < n; ++i) idx[words[i]] = i;
        auto dfs = [&](const auto &self, int i) {
            int &ans = dp[i];
            if (ans != -1) return ans;
            ans = 1;
            for (int skip = 0; skip < int(words[i].size()); ++skip) {
                string t = "";
                t += (words[i].substr(0, skip)) + (words[i].substr(skip + 1));
                if (idx.count(t))
                    ans = max(ans, 1 + self(self, idx[t]));
            }
            return ans;
        };
        int res = 0;
        for (int i = 0; i < n; ++i) res = max(res, dfs(dfs, i));
        return res;
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution s;
    return 0;
}
