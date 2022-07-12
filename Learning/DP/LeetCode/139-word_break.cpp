#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& dict) {
        int n = int(size(s));
        bool dp[301] = {false};
        // dp[i] = true if we can make a suffix [i, n] of s from wordDict
        dp[n] = true;  // empty is valid
        for (int i = n - 1; i >= 0; --i) {
            string word;
            for (int j = i; j < n; ++j) {
                word.push_back(s[j]);
                if (word.size() > 20) break;  // word len limit
                if (find(begin(dict), end(dict), word) != dict.end() && dp[j + 1]) {
                    // if s[j + 1, n] exists and word i.e. s[i, j] exists, then s[i, n] does
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};