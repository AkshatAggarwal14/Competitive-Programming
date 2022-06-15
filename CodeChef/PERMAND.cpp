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
    ll n;
    cin >> n;
    if (n == 1) return void(cout << "1\n1\n");
    if (n & 1) return void(cout << "-1\n");
    for (ll i = 1; i <= n; ++i) cout << i << ' ';
    cout << '\n';
    vector<ll> b(n + 1, 0);
    for (ll i = n; i >= 1; i--) {
        if (b[i] == 0) {
            ll bit = -1;
            for (ll j = 0; j <= 30; ++j)
                if (i & (1 << j)) bit = j;
            ll all1s = (1 << (bit + 1)) - 1;
            b[i] = (all1s ^ i), b[all1s ^ i] = i;
        }
    }
    for (ll i = 1; i <= n; ++i) cout << b[i] << ' ';
    cout << '\n';
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
