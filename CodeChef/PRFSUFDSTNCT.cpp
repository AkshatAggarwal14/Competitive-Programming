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
    vector<ll> p(n), s(n);
    for (auto &it : p) cin >> it;
    for (auto &it : s) cin >> it;
    for (ll i = 0; i < n; ++i) {
        if (p[i] > i + 1) return void(cout << "NO\n");
        if (i > 0 && p[i] < p[i - 1]) return void(cout << "NO\n");
    }
    if (s[0] != p.back()) return void(cout << "NO\n");
    reverse(all(s));
    for (ll i = 0; i < n; ++i) {
        if (s[i] > i + 1) return void(cout << "NO\n");
        if (i > 0 && s[i] < s[i - 1]) return void(cout << "NO\n");
    }
    reverse(all(s));
    // now actual logic
    for (ll t = 0; t < 2; t++) {
        ll num = 1, used = 1;
        for (ll i = 1; i < n; i++) {
            if (p[i - 1] < p[i]) num++;
            if (s[i - 1] > s[i]) used++;
            if (num < used) return void(cout << "NO\n");
        }
        swap(s, p);
        reverse(all(p));
        reverse(all(s));
    }
    cout << "YES\n";
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
