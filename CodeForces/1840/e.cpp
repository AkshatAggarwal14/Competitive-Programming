#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    string s[2];
    cin >> s[0] >> s[1];
    ll T, q;
    cin >> T >> q;
    queue<pair<ll, ll>> toUnblock;
    ll diffUnblocked = 0;
    ll n = ll(s[0].size());
    for (ll i = 0; i < n; ++i) {
        if (s[0][i] != s[1][i]) {
            ++diffUnblocked;
        }
    }

    for (ll i = 0; i < q; ++i) {
        while (!toUnblock.empty() && toUnblock.front().first == i) {
            ll pos = toUnblock.front().second;
            if (s[0][pos] != s[1][pos]) ++diffUnblocked;
            toUnblock.pop();
        }
        ll type;
        cin >> type;
        if (type == 1) {
            ll pos;
            cin >> pos, --pos;
            // TODO: block characters at given pos

            if (s[0][pos] != s[1][pos]) --diffUnblocked;
            toUnblock.emplace(i + T, pos);
        } else if (type == 2) {
            ll c1, pos1, c2, pos2;
            cin >> c1 >> pos1 >> c2 >> pos2, --c1, --c2, --pos1, --pos2;
            // TODO: swap unblocked characters

            diffUnblocked -= (s[0][pos1] != s[1][pos1]) + (s[0][pos2] != s[1][pos2]);  // remove
            swap(s[c1][pos1], s[c2][pos2]);                                            // swap
            diffUnblocked += (s[0][pos1] != s[1][pos1]) + (s[0][pos2] != s[1][pos2]);  // update
        } else {
            cout << (diffUnblocked ? "NO" : "YES") << '\n';
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
