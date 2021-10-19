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
    ll k;
    vector<ll> d(3);
    cin >> d[0] >> d[1] >> d[2] >> k;
    ranges::sort(d);
    if (k >= d[0] + d[1] + d[2] - 3) {
        cout << d[0] * d[1] * d[2];
        return;
    }
    // this will handle remaining too
    ll c1, c2, c3;
    c1 = min(d[0] - 1, k / 3);
    k -= c1;
    c2 = min(d[1] - 1, k / 2);
    k -= c2;
    c3 = min(d[2] - 1, k);
    cout << (c1 + 1) * (c2 + 1) * (c3 + 1) << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}