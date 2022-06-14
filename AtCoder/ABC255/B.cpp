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

void test() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<array<int, 2>> xy(n);
    for (auto &it : a) cin >> it, --it;
    for (auto &[x, y] : xy) cin >> x >> y;
    vector<bool> check(n, false);
    for (auto &it : a) check[it] = true;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            ll min_dist = INF;
            for (int j = 0; j < k; ++j) {
                ll dist = (xy[i][0] - xy[a[j]][0]) * 1LL * (xy[i][0] - xy[a[j]][0]) +
                          (xy[i][1] - xy[a[j]][1]) * 1LL * (xy[i][1] - xy[a[j]][1]);
                min_dist = min(min_dist, dist);
            }
            ans = max(ans, sqrt(min_dist));
        }
    }
    cout << ans << '\n';
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
