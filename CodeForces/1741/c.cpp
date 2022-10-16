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
    ll sum = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x, sum += x;
    vector<ll> div;
    for (ll i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            div.push_back(i);
            if (i != sum / i) div.push_back(sum / i);
        }
    }
    ll ans = n;
    for (auto &x : div) {
        // sum for a split
        ll sm = 0, len = 0, mx = 0;
        bool flag = true;
        for (ll i = 0; i < n; ++i) {
            sm += a[i];
            ++len;
            if (sm > x) {
                flag = false;
                break;
            }
            if (sm == x) {
                mx = max(mx, len);
                sm = 0;
                len = 0;
            }
        }
        if (!flag) continue;
        ans = min(ans, mx);
    }
    cout << ans << '\n';
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
