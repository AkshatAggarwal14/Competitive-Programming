#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    // choose one root
    // A -- root -- B <- this structure

    ll n, m;
    cin >> n >> m;
    vector<ll> mark(n, 0);
    ll a, b, c;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        mark[b - 1] = 1;
    }
    ll root = find(mark.begin(), mark.end(), 0LL) - mark.begin() + 1;
    for (ll i = 1; i <= n; ++i)
        if (i != root) cout << root << ' ' << i << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}