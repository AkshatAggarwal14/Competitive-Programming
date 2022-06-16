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

ll ask(ll L, ll R) {
    cout << "? " << L << ' ' << R << endl;
    ll res;
    cin >> res;
    return res;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> queries(n), ans(n, 0);  // queries[i] = ask(1,i+2)
    queries[0] = ask(2, n);
    for (ll i = 1; i < n; ++i) queries[i] = ask(1, i + 1);
    ans[0] = queries[n - 1] - queries[0];
    ans[1] = queries[1] - ans[0];
    for (ll i = 2; i < n; ++i) ans[i] = queries[i] - queries[i - 1];
    cout << "! ";
    for (auto &x : ans) cout << x << ' ';
    cout << endl;
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}