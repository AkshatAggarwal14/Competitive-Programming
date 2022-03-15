// Choice Diagram:
// Item, I1 (W1) -> W1 > W -> cant choose
//               -> W1<= W -> can choose -> Chosen?
//                                       -> Not chosen.

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

void test() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i) cin >> wt[i];
    for (int i = 0; i < n; ++i) cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    auto dfs = [&](const auto &self, int N, int weight) {
        int &ans = dp[N][weight];
        if (ans != -1) return ans;
        if (N == 0 || weight == 0) return ans = 0;
        // choice diagram
        if (wt[N] <= W) {  // included or not?
            ans = max(val[N] + self(self, N - 1, weight - wt[N]), self(self, N - 1, weight));
            return ans;
        } else {  // no way to include as heavier than the bag's capacity
            return ans = self(self, N - 1, weight);
        }
        assert(false);
        return -1;
    };

    cout << dfs(dfs, n, W) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
