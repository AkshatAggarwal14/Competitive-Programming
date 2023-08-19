#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 501, INF = 1e18;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<ll>> prev(N, vector<ll>(N, -1));
    auto curr = prev;

    ll n, l, k;
    cin >> n >> l >> k;
    vector<ll> coord(n), speed(n);
    for (auto &x : coord) cin >> x;
    for (auto &v : speed) cin >> v;
    coord.push_back(l);

    for (ll j = 0; j < n; ++j) {
        for (ll kk = 0; kk <= k; ++kk) {
            prev[j][kk] = 0;
            curr[j][kk] = INF;
        }
    }

    for (ll index = n - 1; index >= 0; --index) {
        for (ll lastLeft = n - 1; lastLeft >= 0; --lastLeft) {
            for (ll toRemove = 0; toRemove <= k; ++toRemove) {
                ll ans = INF;

                if (toRemove > 0) ans = min(ans, prev[lastLeft][toRemove - 1] +
                                                     speed[lastLeft] * (coord[index + 1] - coord[index]));
                ans = min(ans, prev[index][toRemove] + speed[index] * (coord[index + 1] - coord[index]));

                curr[lastLeft][toRemove] = ans;
            }
        }
        prev = curr;
    }

    cout << curr[0][k] << '\n';

    return 0;
}
