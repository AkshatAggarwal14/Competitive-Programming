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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = n;
    for (ll pos = 1; pos * pos <= n; ++pos) {
        if (n % pos == 0) {
            map<string, ll> splits;
            for (ll i = 0; i < n; i += pos) {
                string sub = s.substr(i, pos);
                ++splits[sub];
            }

            if (splits.size() == 1) {
                ans = min(ans, pos);
            } else if (splits.size() == 2) {
                ll unequal = 0;
                auto [s1, c1] = *(splits.begin());
                auto [s2, c2] = *(next(splits.begin()));

                if (c1 == 1 or c2 == 1) {
                    for (ll j = 0; j < pos; ++j) {
                        if (s1[j] != s2[j]) {
                            ++unequal;
                        }
                    }
                    if (unequal == 1) {
                        ans = min(ans, pos);
                    }
                }
            }

            pos = n / pos;

            splits.clear();
            for (ll i = 0; i < n; i += pos) {
                string sub = s.substr(i, pos);
                ++splits[sub];
            }
            if (splits.size() == 1) {
                ans = min(ans, pos);
            } else if (splits.size() == 2) {
                ll unequal = 0;
                string s1 = splits.begin()->first;
                string s2 = next(splits.begin())->first;
                for (ll j = 0; j < pos; ++j) {
                    if (s1[j] != s2[j]) {
                        ++unequal;
                    }
                }
                if (unequal == 1) {
                    ans = min(ans, pos);
                }
            }

            pos = n / pos;
        }
    }

    cout << ans << '\n';
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
