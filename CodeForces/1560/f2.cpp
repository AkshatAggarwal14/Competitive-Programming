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

int dp[10][2][1024];

void test() {
    ll n, k;
    cin >> n >> k;
    string s = to_string(n);

    memset(dp, -1, sizeof(dp));
    ll res = INF;

    function<int(int, int, int, ll)> dfs = [&](int i, bool tight, int mask, ll num) {
        if (__builtin_popcount(mask) > k) return 0;

        if (i == int(s.size())) {
            res = min(res, num);
            return 1;
        }

        int &ans = dp[i][tight][mask];
        if (ans != -1) return ans;

        ans = 0;

        int lb = 0;
        if (tight) lb = int(s[i] - '0');

        for (int dig = lb; dig <= 9; ++dig) {
            // return as soon as you find 'true'
            if (dfs(i + 1,
                    tight and (dig == lb),
                    mask | (1 << dig),
                    num * 10 + dig)) {
                return ans = 1;
            }
        }

        return ans;
    };

    dfs(0, true, 0, 0);
    cout << res << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
