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
    vector<ll> h(3), w(3);
    for (ll &H : h) cin >> H;
    for (ll &W : w) cin >> W;
    ll ways = 0;
    vector<vector<ll>> mat(3, vector<ll>(3, 0));
    for (ll v1 = 1; v1 <= min(h[0], w[0]); ++v1) {
        for (ll v2 = 1; v2 <= min(h[0], w[1]); ++v2) {
            for (ll v3 = 1; v3 <= min(h[1], w[0]); ++v3) {
                for (ll v4 = 1; v4 <= min(h[1], w[1]); ++v4) {
                    mat[0][0] = v1;
                    mat[0][1] = v2;
                    mat[1][0] = v3;
                    mat[1][1] = v4;
                    mat[2][0] = w[0] - v1 - v3;
                    if (mat[2][0] <= 0) continue;
                    mat[2][1] = w[1] - v2 - v4;
                    if (mat[2][1] <= 0) continue;
                    mat[0][2] = h[0] - v1 - v2;
                    if (mat[0][2] <= 0) continue;
                    mat[1][2] = h[1] - v3 - v4;
                    if (mat[1][2] <= 0) continue;
                    mat[2][2] = h[2] - mat[2][0] - mat[2][1];
                    if (mat[2][2] <= 0) continue;
                    if (mat[0][0] + mat[0][1] + mat[0][2] != h[0]) continue;
                    if (mat[1][0] + mat[1][1] + mat[1][2] != h[1]) continue;
                    if (mat[2][0] + mat[2][1] + mat[2][2] != h[2]) continue;
                    if (mat[0][0] + mat[1][0] + mat[2][0] != w[0]) continue;
                    if (mat[0][1] + mat[1][1] + mat[2][1] != w[1]) continue;
                    if (mat[0][2] + mat[1][2] + mat[2][2] != w[2]) continue;
                    ++ways;
                }
            }
        }
    }
    cout << ways << '\n';
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
