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
    for (auto &A : a) cin >> A;
    vector<ll> b(n);
    for (auto &B : b) cin >> B;
    set<ll> others;
    for (ll i = 0; i < n; ++i) {
        if (a[i] < b[i]) return void(cout << "NO\n");
        if (b[i] != 0) {
            others.insert(a[i] - b[i]);
        }
    }
    if (others.empty()) {
        cout << "YES\n";
        return;
    }
    if (sz(others) > 1) return void(cout << "NO\n");
    ll k = *others.begin();
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        c[i] = max(a[i] - k, 0LL);
    }
    cout << ((b == c) ? "YES\n" : "NO\n");
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
