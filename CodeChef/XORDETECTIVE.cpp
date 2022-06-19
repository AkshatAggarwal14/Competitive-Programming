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
    ll q;
    cin >> q;
    vector<ll> Q(30);
    auto ask = [&](ll x) {
        cout << "? " << x << endl;
        ll res;
        cin >> res;
        return res;
    };
    for (ll i = 0; i < 30; ++i) Q[i] = ask(1 << i);
    ll a, b = 0;
    for (ll i = 0; i < 30; ++i) {
        if (Q[i] & (1 << i)) {
            b |= (1 << i);
        }
    }
    cout << "? " << a << ' ' << b << endl;
    // dbg(Q);
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
