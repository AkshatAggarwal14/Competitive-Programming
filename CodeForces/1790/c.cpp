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
    ll n;
    cin >> n;
    vector<ll> cnt(n + 1, 0);
    vector<vector<ll>> a(n, vector<ll>(n - 1));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n - 1; ++j) {
            cin >> a[i][j];
        }
        ++cnt[a[i][0]];
    }
    dbg(cnt);
    ll gg = -1;
    for (ll i = 1; i <= n; ++i) {
        if (cnt[i] == n - 1) {
            cout << i << ' ';
            gg = i;
            break;
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (a[i][0] != gg) {
            for (auto &x : a[i]) {
                cout << x << ' ';
            }
            cout << '\n';
            break;
        }
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
