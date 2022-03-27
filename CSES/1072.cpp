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
    // ways to arrange 1 knight in n^2 box = n^2
    // ways to arrange another knight on a different box = n^2 - 1
    // total ways to arrange two different knights = n^2 (n^2 - 1)
    // total ways to arrange two identical knights = n^2 (n^2 - 1) / 2
    // two knights attacking each other will form a 2*3 or 3*2 rectangle
    // numner of squares of form 2 * 3 or 3 * 2
    //      = (n - 2) * (n - 1) // 3 * 2
    //      + (n - 1) * (n - 2) // 2 * 3
    // also as we have 2 knights, thus 2 ways for each box, so
    // total ways for knights = 4 * (n - 1) * (n - 2)
    // answer is total ways - attacking
    // n^2 (n^2 - 1) / 2 - 4 * (n - 1) * (n - 2)
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << '\n';
    }
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
