// https://leetcode.com/problems/find-the-shortest-superstring/description/
#include <bits/stdc++.h>
using namespace std;

int cost[12][12];
pair<int, int> dp[1 << 12][13];

int merge(const string &s1, const string &s2) {
    int ans = 0, n = int(s1.size()), m = int(s2.size());
    for (int i = 0; i < n; ++i) {
        int tans = 0;
        for (int j = 0; j < m and i + j < n and s1[i + j] == s2[j]; ++j)
            ++tans;
        if (i + tans == n) ans = max(ans, tans);
    }
    return ans;
}

string mergeString(const string &s1, const string &s2) {
    int ans = merge(s1, s2);
    return s1 + s2.substr(ans);
}

class Solution {
   public:
    string shortestSuperstring(vector<string> &words) {
        int n = int(words.size());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cost[i][j] = merge(words[i], words[j]);
            }
        }

        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int bit = 0; bit < n; ++bit) {
                dp[mask][bit] = {-1, -1};
            }
        }

        // dp[mask][j] = [maximum overlaps superstring from this mask such that j was the last string added, parent]
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = {0, -1};
        }

        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int bit = 0; bit < n; ++bit) {
                if ((mask >> bit) & 1) {
                    int oldMask = (mask ^ (1 << bit));
                    if (oldMask == 0) continue;

                    for (int last = 0; last < n; ++last) {
                        if (bit != last and ((oldMask >> last) & 1)) {
                            int tans = dp[oldMask][last].first + cost[last][bit];

                            if (tans > dp[mask][bit].first) {
                                dp[mask][bit].first = tans;
                                dp[mask][bit].second = last;
                            }
                        }
                    }
                }
            }
        }

        // int sum = 0;
        // for(auto &word: words) sum += word.size();
        // for(int i = 0; i < n; ++i) {
        //     cout << sum - dp[(1 << n) - 1][i].first << ' ';
        // }
        // cout << '\n';

        int sIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][sIndex]) {
                sIndex = i;
            }
        }

        vector<int> path;
        int sMask = (1 << n) - 1;
        while (sIndex != -1) {
            path.push_back(sIndex);
            int id = dp[sMask][sIndex].second;
            sMask ^= (1 << sIndex);
            sIndex = id;
        }

        string res;
        while (!path.empty()) {
            res = mergeString(res, words[path.back()]);
            path.pop_back();
        }

        return res;
    }
};