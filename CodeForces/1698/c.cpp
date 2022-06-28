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
    for (auto &i : a) cin >> i;
    ll pos = 0, neg = 0, zero = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 0) ++zero;
        if (a[i] > 0) ++pos;
        if (a[i] < 0) ++neg;
    }
    if (pos >= 3 || neg >= 3) return void(cout << "NO\n");
    zero = min(zero, 3LL);
    vector<ll> a_n;
    set<ll> has;
    for (ll i = 0; i < n; ++i)
        if (a[i] != 0) a_n.push_back(a[i]), has.insert(a[i]);
    for (ll i = 0; i < zero; ++i) a_n.push_back(0), has.insert(0);
    n = sz(a_n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            for (ll k = j + 1; k < n; ++k) {
                if (!has.count(a_n[i] + a_n[j] + a_n[k]))
                    return void(cout << "NO\n");
            }
        }
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
