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

const ll N = 1200;
array<ll, N + 1> lp;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void Solution() {
    ll n;
    cin >> n;
    vector<array<ll, 2>> edges;
    for (ll i = 1; i < n; ++i) edges.push_back({i, i + 1});
    edges.push_back({n, 1});  // each node has degree 2 rn
    for (ll i = 1; i <= n - n / 2; ++i) {
        if (lp[sz(edges)] == sz(edges)) {  // if size is prime, break and print
            cout << sz(edges) << '\n';
            for (auto &x : edges) cout << x[0] << ' ' << x[1] << '\n';
            return;
        }
        edges.push_back({i, i + n / 2});  // adding 1 degree to 1 -> n/2, 2 -> n/2+1
    }
    dbg(edges);
}
//! there is a prime between n and 3n/2
/*
for (ll i = 1; i < 1000; ++i) {
    ll it = *ranges::lower_bound(pr, i);
    if (it >= i && 2 * it <= 3 * i)
        continue;
    else
        cout << i << ' ' << it << ' ' << 3 * i / 2 << '\n';
}
*/

// clang-format off
int main() {
    fill();
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