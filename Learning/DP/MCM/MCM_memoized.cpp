#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const int INF = INT_MAX;

void test() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    int num_matrices = n - 1;
    // As (i, j) changes so use in dp table
    vector<vector<int>> dp(num_matrices + 1, vector<int>(num_matrices + 1, -1));
    auto cost = [&](const auto &self, int i, int j) -> int {
        if (i >= j) return 0;
        int &ans = dp[i][j];
        if (ans != -1) return ans;
        ans = INF;
        for (int k = i; k < j; ++k) {
            int left = self(self, i, k);
            int right = self(self, k + 1, j);
            int multiply_both = arr[i - 1] * arr[k] * arr[j];
            int temp = left + right + multiply_both;
            ans = min(ans, temp);
        }
        return ans;
    };
    cout << cost(cost, 1, num_matrices) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
