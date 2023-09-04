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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2) {
        string t1, t2;
        for (int i = 0; i < n; ++i) {
            if (i & 1)
                t1 += s[i];
            else
                t2 += s[i];
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                s[i] = t1[pos1++];
            } else {
                s[i] = t2[pos2++];
            }
        }
    } else {
        sort(s.begin(), s.end());
    }

    cout << s << '\n';
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
