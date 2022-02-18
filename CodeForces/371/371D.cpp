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
    ll n;
    cin >> n;
    vector<ll> capacity(n);
    for (ll &C : capacity) cin >> C;
    set<ll> unfilled;
    for (ll i = 0; i < n; ++i) unfilled.insert(i);
    auto orig(capacity);
    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll p, x;
            cin >> p >> x, --p;
            auto it = unfilled.lower_bound(p);
            if (it == unfilled.end()) continue;
            p = *it;
            while (true) {
                if (p >= n) break;
                ll to_dec = min(capacity[p], x);
                capacity[p] -= to_dec;
                x -= to_dec;
                if (capacity[p] == 0) unfilled.erase(p);
                if (x == 0) break;
                ++p;
            }
        } else {
            ll k;
            cin >> k, --k;
            cout << orig[k] - capacity[k] << '\n';
        }
    }
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