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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<vector<ll>> cycles;
    vector<ll> vis(n, -1);
    ll X = 0;
    ll curr = 0, prev = -1, steps = 0;
    while (vis[curr] == -1) {
        vis[curr] = steps++;
        prev = curr;
        curr += a[X % n];
        curr %= n;
        X += a[X % n];
    }
    ll cycle_len = vis[prev] - vis[curr] + 1;
    ll steps_before = vis[curr];
    dbg(steps_before);
    ll ans = 0;
    if (k >= steps_before) {  // solve for inside cycle
        dbg(k, steps_before);
        ll sum_cycle = 0;
        for (ll i = 0; i < n; ++i) {
            if (vis[i] <= vis[prev] && vis[i] >= vis[curr]) sum_cycle += a[i];
        }
        k -= steps_before;
        ll left = k;
        ll total = left / cycle_len;
        ll steps_to_do = left % cycle_len;
        dbg(total, steps_to_do, left, cycle_len, curr, prev);
        ans += sum_cycle * total;     // for complete cycles
        for (ll i = 0; i < n; ++i) {  //  left over inside cycle
            if (vis[i] < vis[curr] + steps_to_do && vis[i] >= vis[curr]) ans += a[i];
        }
        dbg(ans);
    }
    dbg(k, vis);
    for (ll i = 0; i < n; ++i) {  // leftover before cycle
        if (vis[i] <= min(k - 1, vis[curr] - 1) && vis[i] >= 0) ans += a[i];
    }
    cout << ans << '\n';
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