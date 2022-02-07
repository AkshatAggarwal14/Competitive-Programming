#include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;

const int N = 2 * (1e4 + 10);
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> occurences(N, 0);
        vector<vector<int>> res;
        bool flag1 = false, flag2 = false;
        for (auto& x : intervals) {
            ++occurences[2 * x[0]], --occurences[2 * (x[1]) + 1];
            if (x[0] == 0 && x[1] == 0)
                flag1 = true;
            else if (x[0] == 0)
                flag2 = true;
        }
        if (flag1 && !flag2) res.push_back({0, 0});
        for (int i = 1; i < N; ++i) occurences[i] += occurences[i - 1];
        for (auto& x : occurences) x = !!(x);
        int L = -1, R = -1;
        for (int i = 1; i < N; ++i) {
            if (!occurences[i]) L = -1, R = -1;
            if (occurences[i]) {
                L = i;
                while (occurences[i]) {
                    R = i;
                    ++i;
                }
                res.push_back({L / 2, R / 2});
                --i;
            }
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    Solution s;
    vector<vector<int>> v = {{8, 8}, {1, 3}, {2, 6}, {7, 7}, {0, 0}, {10, 15}};
    // vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> v = {{1, 4}, {4, 5}};
    // vector<vector<int>> v = {{1, 4}, {5, 7}};
    dbg(s.merge(v));
    return 0;
}