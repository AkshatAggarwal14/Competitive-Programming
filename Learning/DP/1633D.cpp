#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const ll N = 1005;
const ll INF = 1e18;

ll knapsack(ll W, vector<ll> wt, vector<ll> val) {
    dbg(W, wt, val);
    int n = int(wt.size());
    assert(int(val.size()) == n);
    vector<vector<ll>> dp(2, vector<ll>(W + 1, -1));
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0) {  //! as items can have weight 0, so cant initalise w to 0
                dp[i % 2][w] = 0;
            } else {
                dp[i % 2][w] = dp[(i - 1) % 2][w];
                if (wt[i - 1] <= w)
                    dp[i % 2][w] = max(val[i - 1] + dp[(i - 1) % 2][w - wt[i - 1]], dp[i % 2][w]);
            }
        }
        dbg(i, dp);
    }
    return dp[n % 2][W];
}

int main() {
    vector<ll> operations(N + 1, INF);
    operations[1] = operations[0] = 0;
    for (ll par = 1; par <= N; par++) {
        for (ll child = 1; child <= N; child++) {
            ll val = par + (par / child);
            if (val <= N) operations[val] = min(operations[val], operations[par] + 1);
        }
    }
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> op(n), coins(n);
        for (ll &B : op) cin >> B, B = operations[B];
        for (ll &C : coins) cin >> C;
        // DP, atmost k operations, maximise coins
        // max(operations[i]) = 12, thus min(k, 12 * n)
        cout << knapsack(min(k, 12 * n), op, coins) << '\n';
    }
    return 0;
}

/*
1
4 4
1 7 5 2
2 6 5 2

*/