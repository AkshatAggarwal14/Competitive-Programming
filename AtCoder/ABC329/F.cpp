#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, q;
    cin >> n >> q;
    vector<set<ll>> a(n);
    vector<ll> id(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        a[i].insert(num);
        id[i] = i;
    }

    while (q--) {
        ll u, v;
        cin >> u >> v, --u, --v;

        ll &U = id[u];
        ll &V = id[v];
        if (a[U].size() > a[V].size()) {
            swap(U, V);
        }

        auto it = a[U].begin();
        while (it != a[U].end()) {
            a[V].insert(*it);
            it = a[U].erase(it);
        }

        cout << a[V].size() << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}