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
    ll n, q;
    cin >> n >> q;
    map<ll, ll> first, last;
    for (ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        if (!first.count(num)) first[num] = i;
        last[num] = i;
    }
    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (!first.count(a) || !last.count(b))
            cout << "NO\n";
        else {
            if (first[a] <= last[b])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
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
