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
    ll n, ones;
    cin >> n >> ones;
    ll zeroes = n - ones;
    // fill 0s in gaps of 1s
    ll gaps = ones + 1;
    ll how_many = zeroes / gaps;
    ll how_many_larger = zeroes % gaps;
    ll how_many_smaller = gaps - how_many_larger;
    ll zero_subs = how_many_smaller * (how_many) * (how_many + 1) / 2 +
                   how_many_larger * (how_many + 1) * (how_many + 2) / 2;
    cout << n * (n + 1) / 2 - zero_subs << '\n';
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
