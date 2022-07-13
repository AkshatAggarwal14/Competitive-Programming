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
    vector<ll> c(n);
    map<ll, ll> cnt;
    ll mx = 0;
    for (ll &C : c) cin >> C, ++cnt[C], mx = max(mx, C);
    // if max element is single it cant be paired
    ll cc = 0, other = 1;
    for (auto &[x, y] : cnt) {
        other = max(other, y);
        cc += (y == 1);
    }
    if (cc == 1 && cnt[mx] == 1 && other == 2) return void(cout << "2\n");
    cout << (cc + 1) / 2 << '\n';
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
