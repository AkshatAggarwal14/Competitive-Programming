#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    // pick farthest one at each station
    ll n, m;
    cin >> n >> m;
    vector<multiset<ll>> g(n);
    ll un_delivered = 0;
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        g[u].insert(v);
        ++un_delivered;
    }

    auto farthest = [&](ll from, const multiset<ll> &G) -> ll {
        ll max_dist = 0, ans = -1;
        for (const auto &toffee : G) {
            ll dist = (toffee - from + n) % n;
            if (dist > max_dist) {
                max_dist = dist;
                ans = toffee;
            }
        }
        return ans;
    };

    auto simulate = [&](ll index) {
        vector<multiset<ll>> n_g(all(g));
        ll cnt = un_delivered;
        ll steps = 0;
        multiset<ll> on_train;
        while (cnt > 0) {
            index %= n;
            ll which_toffee_farthest = farthest(index, n_g[index]);
            if (which_toffee_farthest != -1)  // no more toffee at this station?
                n_g[index].erase(n_g[index].find(which_toffee_farthest));
            on_train.insert(which_toffee_farthest);  // insert farthest from this station
            cnt -= on_train.count(index);            // drop all for this station
            on_train.erase(index);
            ++steps, ++index;
        }
        return steps - 1;
    };
    for (ll i = 0; i < n; ++i) cout << simulate(i) << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}