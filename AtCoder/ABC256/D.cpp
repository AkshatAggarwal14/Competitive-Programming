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

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    int n = int(intervals.size());
    int i = 0;
    while (i < n) {
        int x = intervals[i][0];
        int y = intervals[i][1];
        while (i < n && y >= intervals[i][0]) {
            y = max(y, intervals[i][1]);
            i++;
        }
        ans.push_back({x, y});
    }
    return ans;
}

void test() {
    ll n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (auto &i : v) cin >> i[0] >> i[1];
    sort(all(v));
    auto ans = merge(v);
    for (auto &i : ans) cout << i[0] << ' ' << i[1] << '\n';
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
