#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const int INF = 1e9 + 50;

void test() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (auto &W : w) cin >> W;
    // dp[mask] = Minimum {rides, space_left} for a certain subset (mask)
    vector<pair<int, int>> dp((1 << n));

    dp[0] = {1, 0};

    for (int mask = 1; mask < (1 << n); ++mask) {
        pair<int, int> &ans = dp[mask];

        ans = make_pair(n, INF);

        for (int bit = 0; bit < n; ++bit) {
            if ((mask >> bit) & 1) {
                pair<int, int> tans = dp[mask ^ (1 << bit)];
                if (tans.second + w[bit] <= x) {
                    // accomodate another person in this ride
                    tans.second += w[bit];
                } else {
                    // start new ride for this person
                    tans.first += 1;
                    tans.second = w[bit];
                    ans = min(ans, make_pair(tans.first + 1, w[bit]));
                }
                ans = min(ans, tans);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';
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
