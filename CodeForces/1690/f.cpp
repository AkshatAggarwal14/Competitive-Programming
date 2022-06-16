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
    string s;
    cin >> s;
    vector<ll> p(n);
    for (ll &a : p) cin >> a, --a;
    vector<ll> which_cycle(n, -1);
    vector<vector<ll>> cycles;
    ll cycle_number = 0;
    for (ll i = 0; i < n; ++i) {
        ll par = p[i];
        if (which_cycle[par] != -1) continue;
        vector<ll> curr_cycle;
        while (which_cycle[par] == -1) {
            which_cycle[par] = cycle_number;
            curr_cycle.push_back(par);
            par = p[par];
        }
        cycles.push_back(curr_cycle);
        ++cycle_number;
    }
    ll ans = 1;
    for (auto &cycle : cycles) {
        string now = "";
        for (ll &id : cycle) {
            now += s[id];
        }
        string rot = now;
        ll cnt = 0;
        do {
            rotate(rot.begin(), 1 + rot.begin(), rot.end());
            ++cnt;
        } while (rot != now);
        ans = lcm(ans, cnt);
    }
    cout << ans << '\n';
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
