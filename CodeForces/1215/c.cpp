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
    string s, t;
    cin >> n >> s >> t;
    // count of a's and b's at unequal positions should be even to pair them.

    // aa and bb better
    // bb     aa
    vector<ll> ab, ba;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'a' && t[i] == 'b') ab.push_back(i);
        if (s[i] == 'b' && t[i] == 'a') ba.push_back(i);
    }
    vector<array<ll, 2>> ans;
    while (sz(ab) > 1) {
        ll i1 = ab.back();
        ab.pop_back();
        ll i2 = ab.back();
        ab.pop_back();
        ans.push_back({i1, i2});
    }
    while (sz(ba) > 1) {
        ll i1 = ba.back();
        ba.pop_back();
        ll i2 = ba.back();
        ba.pop_back();
        ans.push_back({i1, i2});
    }
    if (!ab.empty() && !ba.empty()) {
        ll i1 = ab.back();
        ll i2 = ba.back();
        ans.push_back({i1, i1});
        ans.push_back({i1, i2});
    } else if (!ab.empty() || !ba.empty()) {
        return void(cout << "-1\n");
    }
    cout << sz(ans) << '\n';
    for (auto &[u, v] : ans) cout << u + 1 << ' ' << v + 1 << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
