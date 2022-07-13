// https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int solve(int n) {
    vector<array<int, 3>> avail;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (i != j && j != k) avail.push_back({i, j, k});
    vector<ll> dp(36);
    for (int i = 1; i <= n; i++) {
        vector<ll> ndp(36);
        for (int j = 0; j < 36; j++) {
            auto &[x1, y1, z1] = avail[j];
            if (i == 1)
                ndp[j] = 1;
            else {
                ll &ans = ndp[j];
                ans = 0;
                for (int k = 0; k < 36; k++) {
                    auto &[x2, y2, z2] = avail[k];
                    if (x1 != x2 && y1 != y2 && z1 != z2) {
                        ans += dp[k];
                        ans %= MOD;
                    }
                }
            }
        }
        swap(ndp, dp);
    }
    ll ans = 0;
    for (int i = 0; i < 36; ++i) {
        ans += dp[i];
        ans %= MOD;
    }
    return int(ans);
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
}