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
    int n;
    cin >> n;
    int aw = 0, ab = 0, bw = 0, bb = 0, i = 0;
    int len = 1, turn = 1;
    while (i < n) {
        int far = min(len, n - i);
        if (turn) {
            // alice - begin with W
            aw += (far + 1) / 2;
            ab += far / 2;
        } else {
            // bob - begin with B
            bb += (far + 1) / 2;
            bw += far / 2;
        }
        turn ^= 1;
        i = i + far;
        len += 4;
    }
    cout << aw + ab << ' ' << bw + bb << '\n';
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
