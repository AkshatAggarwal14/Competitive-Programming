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

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m)), make(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    make[0][0] = grid[0][0];
    for (ll i = 1; i < n; ++i) make[i][0] = make[i - 1][0] + 7;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j < m; ++j) make[i][j] = make[i][j - 1] + 1;
    }
    bool flag = true;
    set<ll> st;
    for (ll i = 0; i < n; ++i) {
        st.clear();
        for (ll j = 0; j < m; ++j) st.insert((grid[i][j] - 1) / 7);
        if (sz(st) != 1) flag = false;
    }
    if (flag && grid == make)
        cout << "Yes\n";
    else
        cout << "No\n";
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}