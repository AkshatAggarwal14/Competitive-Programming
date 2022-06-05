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
    for (ll &A : a) cin >> A;
    vector<vector<ll>> BITS(31);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 31; ++j) {
            if (a[i] & (1LL << j)) {
                BITS[j].push_back(i + 1);
            }
        }
    }
    for (ll i = 0; i < 31; ++i) {
        if (sz(BITS[i]) > 1) {
            cout << "YES\n";
            ll len = sz(BITS[i]);
            cout << len << '\n';
            for (ll j = 0; j < len; ++j) {
                cout << ((j == 0) ? 1 : BITS[i][j - 1] + 1) << ' ';
                cout << ((j == sz(BITS[i]) - 1) ? n : BITS[i][j]) << '\n';
            }
            return;
        }
    }
    cout << "NO\n";
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
