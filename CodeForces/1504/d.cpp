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
    set<pair<ll, ll>> even, odd;  // 1 on odd, 2 on even
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            (((i + j) & 1) ? odd : even).insert({i, j});
    for (ll _ = 0, a; _ < n * n; ++_) {
        cin >> a;
        if (a == 1) {
            if (even.empty()) {
                cout << "3 ";  // as now even already filled
                cout << (*odd.begin()).first << ' ';
                cout << (*odd.begin()).second << endl;
                odd.erase(odd.begin());
            } else {
                cout << "2 ";
                cout << (*even.begin()).first << ' ';
                cout << (*even.begin()).second << endl;
                even.erase(even.begin());
            }
        } else if (a == 2) {
            if (odd.empty()) {
                cout << "3 ";  // as now odd already filled
                cout << (*even.begin()).first << ' ';
                cout << (*even.begin()).second << endl;
                even.erase(even.begin());
            } else {
                cout << "1 ";
                cout << (*odd.begin()).first << ' ';
                cout << (*odd.begin()).second << endl;
                odd.erase(odd.begin());
            }
        } else {
            if (!odd.empty()) {
                cout << "1 ";
                cout << (*odd.begin()).first << ' ';
                cout << (*odd.begin()).second << endl;
                odd.erase(odd.begin());
            } else {
                cout << "2 ";
                cout << (*even.begin()).first << ' ';
                cout << (*even.begin()).second << endl;
                even.erase(even.begin());
            }
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
