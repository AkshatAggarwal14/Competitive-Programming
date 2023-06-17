#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 5006;
const ll MOD = 1e9 + 7;  // 998244353;

int pref[N][N], g[N][N];

void test() {
    memset(pref, 0, sizeof(pref));
    memset(g, 0, sizeof(g));
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            ans += (c == '0');
            g[i][j] = c - '0';
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + g[i][j];
        }
    }
    auto get = [&](int i, int j, int k) {
        // give me rectangle from (i, j) to (i + k - 1, j + k - 1)
        // in prefix coordinates (i + 1, j + 1) to (i + k, j + k)
        return pref[i + k][j + k] + pref[i][j] - pref[i][j + k] - pref[i + k][j];
    };
    // O(sum(k * (n/k) * (m/k))
    // O(nm + nm/4 + nm/9 + ...)
    // O(nmlog(nm))
    ans = min(ans, n * m - ans);
    for (int k = 2; k < max(n, m); ++k) {
        int tans = 0;
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < m; j += k) {
                int getCellValue = get(i, j, k);
                tans += min(getCellValue, k * k - getCellValue);
            }
        }
        ans = min(ans, tans);
    }
    cout << ans << '\n';
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
