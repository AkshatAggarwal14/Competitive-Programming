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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (auto &x : a) cin >> x, ++cnt[x];
    ll mex = 0;
    vector<ll> left, mx;
    while (cnt.count(mex)) {
        mx.push_back(mex);
        for (ll j = 0; j < cnt[mex] - 1; ++j) left.push_back(mex);
        ++mex;
    }
    if (mx.size() > k) {
        cout << k << '\n';
    } else {
        cout << mex << '\n';
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
