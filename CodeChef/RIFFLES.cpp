#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, k;
    cin >> n >> k;
    // if i is even we go to i/2
    // if i is odd we go to n/2 + i/2
    auto next_idx = [&](ll I) {
        if (!(I & 1)) return I / 2;
        return n / 2 + I / 2;
    };
    // finding all cycles and storing
    vector<vector<ll>> cycles;
    vector<bool> vis(n, false);
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<ll> curr_cycle;
        ll cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            cur = next_idx(cur);
            curr_cycle.push_back(cur);
        }
        reverse(all(curr_cycle));
        cycles.push_back(curr_cycle);
    }
    // go thru each cycle and
    // current_cycle[(k + pos in current_cycle) % sz(current_cycle)]
    vector<ll> ans(n, -1);
    for (auto &cycle : cycles)
        for (ll i = 0; i < sz(cycle); ++i)
            ans[cycle[i]] = cycle[(i + k) % sz(cycle)];
    for (auto &x : ans) cout << x + 1 << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}