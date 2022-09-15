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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    ll div = b / n;
    ll left = b % n;
    vector<ll> a(n, div * k);
    a.back() += left * k;
    ll min_sum = b * k;
    if (min_sum > s) return void(cout << "-1\n");
    ll max_sum = min_sum + n * (k - 1);
    if (max_sum < s) return void(cout << "-1\n");
    ll over = s - min_sum;
    for (ll i = 0; i < n; ++i) {
        ll delta = min(k - 1, over);
        a[i] += delta;
        over -= delta;
    }
    for (auto &x : a) cout << x << ' ';
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
