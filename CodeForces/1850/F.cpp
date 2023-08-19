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
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) h[x]++;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 2 * i; j <= n; j += i) {
            h[j] += h[i];
        }
    }
    cout << *max_element(h.begin(), h.end()) << '\n';
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
