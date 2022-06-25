#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int diameter = 0;
    vector<pair<int, int>> dp(n);  // dp[i] = {Max Number of edges, Frequency} in subtree of i.
    auto dfs = [&](const auto& self, int node, int par = -1) -> pair<int, int> {
        int mx = 0;
        int cur = 0, prev = 0;
        for (auto& child : g[node]) {
            if (child == par) continue;
            auto C = self(self, child, node);
            if (C.first >= cur) {
                prev = cur;
                cur = C.first;
            }
            mx = max(mx, C.first);
        }
        diameter = max(diameter, 1 + prev + cur);
        int cnt = 0;
        if (mx == 0) cnt = 1;
        for (auto& child : g[node]) {
            if (child == par) continue;
            auto C = self(self, child, node);
            if (C.first == mx) cnt += C.second;
        }
        return dp[node] = {1 + mx, cnt};
    };
    // if dp[x].f + dp[y].f = diameter length
    // you do ans += dp[x].s * dp[y].s, for a pair of children x, y of u.
    dfs(dfs, 0);
    int ans = 0;
    auto dfs2 = [&](const auto& self, int node, int par = -1) -> void {
        unordered_map<int, int, custom_hash> freq;
        for (auto& child : g[node]) {
            if (child == par) continue;
            self(self, child, node);
            if (freq.count(diameter - 1 - dp[child].first))
                ans += freq[diameter - 1 - dp[child].first] * dp[child].second;
            freq[dp[child].first] += dp[child].second;
        }
    };
    dfs2(dfs2, 0);
    // for root
    if (dp[0].first == diameter) ans += dp[0].second;

    cout << ans << '\n';
    cout << diameter << '\n';
    return 0;
}

/*
1 center:
5
1 2
2 3
2 4
2 5

2 center:
6
1 2
2 3
2 4
4 5
4 6
*/