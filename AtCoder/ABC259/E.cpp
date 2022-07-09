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
    int n;
    cin >> n;
    // if a number has a prime factor with highest power among all, then it contributes +1 if and only if no other number has same power
    // if left all give LCM of overall so add 1
    vector<map<int, int>> a(n);
    map<int, pair<int, vector<int>>> maxi;  // [p, [max(e), indices]]
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0, p, e; j < m; ++j) {
            cin >> p >> e;
            a[i][p] = e;
            maxi[p].first = max(maxi[p].first, e);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &[p, e] : a[i]) {
            if (maxi[p].first == e) {
                maxi[p].second.push_back(i);
            }
        }
    }
    set<int> res;
    for (auto &it : maxi) {
        if (sz(it.second.second) == 1) res.insert(it.second.second[0]);
    }
    int ans = sz(res);
    int rem = !!(n - (sz(res)));
    cout << ans + rem << '\n';
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
