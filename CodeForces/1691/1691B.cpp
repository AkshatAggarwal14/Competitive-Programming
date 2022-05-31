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
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (ll &A : a) cin >> A, ++cnt[A];
    for (auto &[x, y] : cnt)
        if (y == 1) return void(cout << "-1\n");
    vector<vector<ll>> segs;
    ll num = 1;
    segs.emplace_back();
    segs.back().push_back(num);
    for (ll i = 1; i < n; ++i) {
        ++num;
        if (a[i] != a[i - 1]) segs.emplace_back();
        segs.back().push_back(num);
    }
    for (auto &x : segs) {
        rotate(x.begin(), 1 + x.begin(), x.end());
        for (auto &y : x) cout << y << ' ';
    }
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
