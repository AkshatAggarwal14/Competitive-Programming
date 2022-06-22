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
    vector<ll> cnt(n + 10, 0);
    for (auto &i : a) cin >> i, ++cnt[i];
    for (ll i = 1; i <= sz(cnt); ++i)
        cnt[i] += cnt[i - 1];
    auto get_greater = [&](ll i) { return cnt.back() - cnt[i]; };

    vector<ll> atleast(n), atmost(n);
    for (ll i = 0; i < n; ++i)
        atleast[i] = get_greater(i);
    vector<ll> left(n);
    for (ll i = 0; i < n; ++i)
        left[i] = n - a[i];
    ll sum = accumulate(all(left), 0LL);
    vector<ll> to_add(n, sum);
    for (ll i = 0; i < n; ++i)
        if (a[i] < n) to_add[a[i]] -= left[i];
    for (ll i = 0; i < n; ++i)
        atmost[i] = atleast[i] + to_add[i];
    for (ll i = 0; i < n; ++i)
        cout << atleast[i] << ' ' << atmost[i] << '\n';
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
