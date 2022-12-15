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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll cnt = 0;
    vector<ll> v;
    for (auto &x : a) {
        cin >> x;
        ll c = 0;
        while (x % 2 == 0) {
            x /= 2;
            ++c;
        }
        cnt += c;
    }
    for (ll i = 2; i <= n; i += 2) {
        ll c = 0, x = i;
        while (x % 2 == 0) {
            x /= 2;
            ++c;
        }
        v.push_back(c);
    }
    sort(all(v), greater<ll>());
    ll i = 0;
    while (i < sz(v) && cnt < n) {
        cnt += v[i];
        ++i;
    }
    cout << ((cnt < n) ? -1 : i) << '\n';
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
