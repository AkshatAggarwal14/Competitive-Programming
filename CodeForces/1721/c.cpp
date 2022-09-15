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
    vector<ll> a(n), b(n);
    for (auto &A : a) cin >> A;
    for (auto &B : b) cin >> B;
    vector<ll> id;
    for (ll i = 1; i < n; ++i)
        if (a[i] > b[i - 1]) id.push_back(i);
    vector<ll> ans1(n), ans2(n);
    for (ll i = 0; i < n; ++i) {
        ans1[i] = *lower_bound(all(b), a[i]) - a[i];
    }
    for (ll i = 0; i < n; ++i) {
        auto it = upper_bound(all(id), i);
        if (it == id.end()) {
            ans2[i] = b[n - 1] - a[i];
        } else {
            ans2[i] = b[*it - 1] - a[i];
        }
    }

    for (ll i = 0; i < n; ++i) cout << ans1[i] << ' ';
    cout << '\n';
    for (ll i = 0; i < n; ++i) cout << ans2[i] << ' ';
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
