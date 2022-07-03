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
const ll N = 3010;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n;
    bitset<N> b[N], suf;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    ll ans = 0;
    for (int j = 1; j < n - 1; j++) {
        suf.reset();
        for (int k = j + 1; k < n; k++)
            if (b[j][k]) suf[k] = 1;

        for (int i = 0; i < j; i++) {
            if (b[i][j]) {
                ans += (suf & b[i]).count();
            }
        }
    }
    cout << ans;
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
