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

vector<ll> res;
void fill(ll pos, ll cnt, ll cur) {
    if (pos == 18) {
        res.push_back(cur);
        return;
    }
    fill(pos + 1, cnt, cur * 10);
    if (cnt < 3)
        for (ll i = 1; i <= 9; ++i)
            fill(pos + 1, cnt + 1, cur * 10 + i);
}

void Solution() {
    dbg(sz(res));
    ll L, R;
    cin >> L >> R;
    cout << upper_bound(res.begin(), res.end(), R) - lower_bound(res.begin(), res.end(), L) << '\n';
}

// clang-format off
int main() {
    // !
    fill(0LL, 0LL, 0LL);
    res.push_back(1000000000000000000);
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