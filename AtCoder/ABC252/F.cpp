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
    // instead of breaking, join together
    ll n, l;
    cin >> n >> l;
    multiset<ll> st;
    ll sum = 0;
    for (ll i = 0, num; i < n; ++i) {
        cin >> num;
        sum += num;
        st.insert(num);
    }
    if (l > sum) st.insert(l - sum);
    ll ans = 0;
    while (sz(st) > 1) {
        auto it = *st.begin();
        st.erase(st.begin());
        auto it2 = *st.begin();
        st.erase(st.begin());
        ans += (it + it2);
        st.insert(it + it2);
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
