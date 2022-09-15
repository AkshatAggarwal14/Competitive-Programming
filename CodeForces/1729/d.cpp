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
    vector<ll> v(n);
    for (auto &x : v) cin >> x;
    multiset<ll> positives;
    for (ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        v[i] = num - v[i];
        if (v[i] >= 0) positives.insert(v[i]);
    }
    sort(all(v));
    dbg(v);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (v[i] < 0) {
            auto it = positives.lower_bound(-v[i]);
            if (it != positives.end()) {
                ++ans;
                positives.erase(it);
            }
        }
    }
    ans += sz(positives) / 2;
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
