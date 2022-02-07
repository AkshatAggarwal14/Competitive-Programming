#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

//--------------------------------------------------------------------------------

void Better() {
    ll n, k, d;
    cin >> n >> k;
    vector<vector<ll>> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> d, a[d].push_back(i);
    bool flag = (sz(a[0]) == 1);
    flag &= (sz(a[1]) <= k);
    for (ll i = 1; i < n; i++)
        flag &= sz(a[i]) * (k - 1) >= sz(a[i + 1]);
    if (!flag) return void(cout << "-1\n");
    cout << n - 1 << '\n';  // tree
    for (ll i = 0; i <= n - 1; i++) {
        for (ll j = 0; j < sz(a[i + 1]); j++) {
            // connect child to j of parent.-> % -> equally
            cout << a[i][j % sz(a[i])] << ' ' << a[i + 1][j] << '\n';
        }
    }
}

void Solution() {
    ll n, k, p = 1;
    cin >> n >> k;
    vector<ll> d(n), cnt(n, 0), deg(n, 0);
    for (ll &x : d) cin >> x, ++cnt[x];
    ll mx = *ranges::max_element(d);
    // 1, k, k^2, ... <- max nodes with d[0], d[1] ...
    for (ll i = 0; i < n; ++i) {
        if (!cnt[i] || p >= (ll)1e5) break;
        if (cnt[i] > p) return void(cout << "-1\n");
        p *= k;
    }
    // distances 0 1 2 3.. all consecutive should exist
    vector<ll> check(d);
    sort(all(check));
    check.resize(unique(all(check)) - check.begin());
    for (ll i = 1; i < sz(check); ++i)
        if (check[i] != check[i - 1] + 1) return void(cout << "-1\n");
    // joining all children to their parents equally.. %sz(parent)..
    vector<vector<ll>> avail(mx + 1);
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < n; ++i) avail[d[i]].push_back(i);
    for (ll i = 1; i <= mx; ++i) {
        ll parent = i - 1, child = i;
        if (avail[parent].empty()) break;
        for (ll j = 0; j < sz(avail[child]); ++j) {
            ll u = avail[parent][j % sz(avail[parent])];
            ll v = avail[child][j];
            ++deg[u], ++deg[v];
            edges.push_back({u, v});
        }
    }
    // rechecking at the end
    if (*ranges::max_element(deg) > k || edges.empty()) return void(cout << "-1\n");
    cout << sz(edges) << '\n';
    for (auto &[x, y] : edges) cout << x + 1 << ' ' << y + 1 << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Better();
    return 0;
}