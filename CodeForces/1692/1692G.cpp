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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &it : a) cin >> it;
    vector<ll> mark(n - 1);
    for (ll i = 0; i < n - 1; ++i) mark[i] = (a[i] < 2 * (a[i + 1]));
    vector<ll> pref(n);
    partial_sum(all(mark), 1 + pref.begin());
    ll cnt = 0;
    for (ll i = 0; i < n - k; ++i) cnt += (pref[i + k] - pref[i] == k);
    cout << cnt << '\n';
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
