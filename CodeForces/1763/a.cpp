#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
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
    vector<array<int, 2>> a(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < 10; ++j) {
            if ((num >> j) & 1) {
                a[j][1] = 1;
            } else {
                a[j][0] = 1;
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < 10; ++i) {
        if (a[i][0] && a[i][1]) {
            mx += (1 << i);
        }
    }
    cout << mx << '\n';
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