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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char ch[] = {'R', 'G', 'B'};
    vector<string> vv(3);
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < k; ++j) {
            vv[i].push_back(ch[(j + i) % 3]);
        }
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < n - k + 1; ++j) {
            ll x = 0;
            for (ll t = j; t < j + k; ++t) {
                x += (vv[i][t - j] != s[t]);
            }
            ans = min(ans, x);
        }
    }
    cout << ans << '\n';
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