#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    const int MX = 512;
    // dp[x] = the smallest possible ending value of a subsequence which has a xor x
    vector<int> dp(MX, 501);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int x = 1; x < MX; ++x) {
            int prevXor = (x ^ a[i]);
            if (dp[prevXor] < a[i]) {
                dp[x] = min(dp[x], a[i]);
            }
        }
    }

    vector<int> ans;
    for (int x = 0; x < MX; ++x) {
        if (dp[x] < 501) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << '\n';
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
