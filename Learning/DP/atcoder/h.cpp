#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

const ll MOD = 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    char curr;
    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> curr;
            if (curr == '#') continue;
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[h - 1][w - 1] << '\n';
    return 0;
}
