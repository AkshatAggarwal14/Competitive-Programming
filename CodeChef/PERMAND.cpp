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
    // 2 1
    // 4 3 2 1
    // 6 5 4 3 2 1
    // 6 5 4 3 2 1 8 7
    // 2 1 4 3 10 9 8 7 6 5
    // 2 1 12 11 10 9 8 7 6 5 4 3
    ll i = n;
    vector<array<ll, 2>> ans;
    while (true) {
        if (i <= 0) break;
        ll maxi = 1;
        while ((maxi | i) != maxi) maxi = 2 * maxi + 1;
        ll j = maxi ^ i;
        dbg(j, i, maxi);
        if (j > i) break;
        // dbg(j, i);
        ans.push_back({j, i});
        i = j - 1;
    }
    reverse(all(ans));
    dbg(ans);
    vector<ll> b;
    for (auto &x : ans)
        for (ll k = x[1]; k >= x[0]; --k) b.push_back(k);
    dbg(b);
    for (ll k = 0; k < n; ++k) assert((b[k] & (k + 1)) == 0);
    for (ll k = 0; k < n; ++k) cout << b[k] << ' ';
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
