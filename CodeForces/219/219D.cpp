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

void Solution() {
    ll n;
    cin >> n;
    vector<vector<pair<ll, bool>>> g(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back({v, true});   // true means "down" edge. -> real
        g[v].push_back({u, false});  // false means "up" edge -> fake
    }
    /* When we dfs from one root to some vertex i, 
    then number of inversions needed 
    = Count of down from root to i + Count of OTHER UP 
    = Count of down from root to i + count of all ups - count of up from root to i */
    ll UP = 0;
    vector<ll> up_c(n, 0), down_c(n, 0);
    function<void(ll, ll)> dfs = [&](ll node, ll parent) {  // as tree
        for (auto &child : g[node]) {
            if (child.first == parent) continue;
            if (child.second) {
                down_c[child.first] = down_c[node] + 1;  // node -> child is down
                up_c[child.first] = up_c[node];
            } else {
                up_c[child.first] = up_c[node] + 1;  // node -> child is up
                down_c[child.first] = down_c[node];
                ++UP;
            }
            dfs(child.first, node);
        }
    };
    dfs(0, -1);  // dfs
    vector<ll> ans(n, 0);
    for (ll i = 0; i < n; ++i) ans[i] = down_c[i] + UP - up_c[i];
    ll mn = *ranges::min_element(ans);
    cout << mn << '\n';
    for (ll i = 0; i < n; ++i)
        if (ans[i] == mn) cout << i + 1 << ' ';
    cout << '\n';
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
    Solution();
    return 0;
}