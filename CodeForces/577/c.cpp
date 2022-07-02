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
const ll N = 1e3 + 5;
const ll MOD = 1e9 + 7;  // 998244353

bitset<N> P;

void test() {
    ll n;
    cin >> n;
    // prime ^ power find all
    vector<ll> ans;
    for (ll i = 2; i <= n; ++i) {
        if (!P[i]) continue;
        for (ll j = i; j <= n; j *= i) ans.push_back(j);
    }
    cout << sz(ans) << '\n';
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    P.set();
    for (ll i = 2; i < N; ++i) {
        if (!P[i]) continue;
        for (ll j = 2 * i; j < N; j += i) P[j] = 0;
    }
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
