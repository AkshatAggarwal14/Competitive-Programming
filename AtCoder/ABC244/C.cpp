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
    set<ll> st;
    for (ll i = 1; i <= 2 * n + 1; ++i) st.insert(i);
    ll move = 0;
    while (true) {
        if (move % 2 == 0) {
            cout << *st.begin() << endl;
            st.erase(st.begin());
        } else {
            ll q;
            cin >> q;
            if (q == 0) exit(0);
            st.erase(q);
        }
        ++move;
    }
}

int32_t main() {
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
