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
    // height, {idx's}
    // idx, val
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n, INF);
    map<ll, set<ll>> mp;
    while (m--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, h;
            cin >> i >> h;
            ll prev = a[i];
            if (prev != INF) {
                assert(mp.count(prev));
                assert(mp[prev].count(i));
                mp[prev].erase(i);
            }
            mp[h].insert(i);
            a[i] = h;
        } else {
            ll l, r, p;
            cin >> l >> r >> p, --r;
            auto it = mp.upper_bound(p);
            vector<ll> ids;
            vector<ll> to_del;
            for (auto b = mp.begin(); b != it; ++b) {
                auto it2 = b->second.lower_bound(l);
                while (it2 != b->second.end() && *it2 <= r) {
                    ids.push_back(*it2);
                    it2 = b->second.erase(it2);
                }
                if (b->second.empty()) {
                    to_del.push_back(b->first);
                }
            }
            for (auto &x : to_del) {
                mp.erase(x);
            }
            dbg(ids);
            for (auto &x : ids) {
                a[x] = INF;
            }
            cout << sz(ids) << '\n';
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
