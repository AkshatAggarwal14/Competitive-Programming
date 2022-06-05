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

/*
2: 0 (1, 1)
3: 1 (1, 2)
4: 2 (1, 3)
5: 5 (2, 3)
6: 4 (1, 5)
7: 11 (3, 4)
8: 14 (3, 5)
9: 19 (4, 5)
10: 20 (3, 7)
11: 29 (5, 6)
12: 34 (5, 7)
13: 41 (6, 7)
14: 44 (5, 9)
15: 55 (7, 8)
16: 62 (7, 9)
17: 71 (8, 9)
18: 76 (7, 11)
19: 89 (9, 10)
20: 98 (9, 11)
*/

// numbers with given sum and max LCM
pair<ll, ll> pair_with_max_lcm(ll sum) {
    ll A, B;
    if (sum & 1) {
        A = sum / 2;
        B = sum / 2 + 1;
    } else {
        if ((sum / 2) % 2 == 0) {
            A = sum / 2 - 1;
            B = sum / 2 + 1;
        } else {
            A = sum / 2 - 2;
            B = sum / 2 + 2;
        }
    }
    return {A, B};
}

void test() {
    ll n;
    cin >> n;
    if (n == 2) return void(cout << "0\n");
    auto c = pair_with_max_lcm(n);
    cout << lcm(c.first, c.second) - gcd(c.first, c.second) << '\n';
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
