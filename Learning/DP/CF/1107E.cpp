#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using i64 = long long;

template <typename T, typename T_iterable>
vector<pair<T, int>> compress(const T_iterable &items) {
    if (items.empty()) return {};
    vector<pair<T, int>> encoded;
    int count = 0;
    T last = items[0];
    for (const T &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count) encoded.push_back({last, count});
            last = item, count = 1;
        }
    }
    if (count) encoded.push_back({last, count});
    return encoded;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    /*
    ? Observations:
        1. Each group is independed and doesnt affect others '1001010001', here "000" can be deleted without affecting other groups.
        2. Claim:   - either ignore a group for now
                    - delete entirely
                ? We might want to ignore a group, as it may combine with a group later to get better answer.
        ? For a particular group:
        Let length of group be m:   we know removing a substring of len i we get a_i
                                    ! This is rod cutting problem - use it to calc ans for groups of all lengths
        Let string be G1,G2,G3,G4...
        Choice 1: Ans(G1) + Ans[2..S]
        Choice 2: Ans(G2) + Ans[1,3,4..S] -> Ans(G2) + Ans(3..S, Extra=G1)
        Choice 3: And(G2->G4) + Ans(G5->GS, Extra=G1)
        .. so G1 can be combined with G3 or G5 or G7...

        ? dp[i][j][extra]: Best possible score for groups G[i, j] given G[i] has some extra digits combined to it i.e. extra
        ? Ans: dp[1][N][0]: from 1st to Nth group given nothing extra

        ? Recurrences:
            dp[i][j][extra]:    1. rod(size(G_i) + extra) + dp[i + 1][j][0]
                                2. dp[i + 1][i + 1][0] + dp[i + 2][j][extra + G_i]     {collapse G2}
                                3. dp[i + 1][i + 3][0] + dp[i + 4][j][extra + G_i]     {collapse G2G3G4}
                                    ...
     */

    int n;
    string s;
    cin >> n >> s;
    vector<int> pts(n);  // pts[i]: points obtained by deleting substring of given size of only '0' or '1'
    for (auto &p : pts) cin >> p;

    vector<i64> dp_rod(n + 1, 0);
    // rod[j]: maximum points obtained when cutting substring of length j
    for (int len = 1; len <= n; ++len) {
        for (int cut = 1; cut <= len; ++cut) {
            dp_rod[len] = max(dp_rod[len], pts[cut - 1] + dp_rod[len - cut]);
        }
    }

    auto groups = compress<char>(s);
    vector<int> len;
    transform(begin(groups), end(groups), back_inserter(len), [](pair<char, int> &P) {
        return P.second;
    });
    int m = int(size(groups));
    /*
    ? Recurrences:
    dp[i][j][extra]:    1. rod(size(G_i) + extra) + dp[i + 1][j][0]
                        2. dp[i + 1][i + 1][0] + dp[i + 2][j][extra + G_i]     {collapse G2}
                        3. dp[i + 1][i + 3][0] + dp[i + 4][j][extra + G_i]     {collapse G2G3G4}
                            ...
    ! dp[m][m][n]
    */
    vector<vector<vector<i64>>> dp(m + 1, vector<vector<i64>>(m + 1, vector<i64>(n + 1)));
    for (int L = m - 1; L >= 0; --L) {
        for (int R = L; R < m; ++R) {
            for (int extra = 0; extra <= n - len[L]; ++extra) {
                i64 &ans = dp[L][R][extra];
                ans = dp_rod[len[L] + extra] + dp[L + 1][R][0];
                for (int k = 1; L + k <= R; k += 2) {
                    // L + k <= R as we are finding ans for dp[L][R][] right now
                    ans = max(ans, dp[L + 1][L + k][0] + dp[L + 1 + k][R][extra + len[L]]);
                }
            }
        }
    }
    cout << dp[0][m - 1][0] << '\n';
}