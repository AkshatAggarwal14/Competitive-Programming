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
    // convert k to base 9, now our system has 9 digits
    ll k;
    cin >> k;
    string base9;
    while (k) {
        base9.push_back(char(k % 9) + '0');
        k /= 9;
    }
    reverse(base9.begin(), base9.end());
    // now map all digits >= 4 to + 1 them: 4->5, 5->6, ..
    for (auto &x : base9)
        if (x >= '4') ++x;
    cout << base9 << '\n';
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
