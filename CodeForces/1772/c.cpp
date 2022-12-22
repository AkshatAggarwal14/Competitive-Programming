#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int k, n;
    cin >> k >> n;
    for (int mx_dist = 9; mx_dist >= 1; --mx_dist) {
        vector<int> res;
        int last = n, dec = mx_dist;
        while (int(res.size()) < k) {
            res.push_back(last);
            last -= dec;
            --dec;
            if (dec <= 0) break;
        }
        while (int(res.size()) < k) res.push_back(res.back() - 1);
        reverse(res.begin(), res.end());
        bool flag = false;
        for (auto &x : res)
            if (x <= 0) flag = true;
        if (flag) continue;

        for (auto &x : res) cout << x << ' ';
        cout << '\n';
        return;
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
