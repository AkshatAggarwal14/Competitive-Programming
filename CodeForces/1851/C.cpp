#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 2e5 + 5;

void test() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (a[0] == a[n - 1]) {
        int freq = int(count(a.begin(), a.end(), a[0]));
        cout << ((freq >= k) ? "YES\n" : "NO\n");
        return;
    }

    vector<vector<int>> locations(n + 1);
    for (int i = 0; i < n; ++i) locations[a[i]].push_back(i);

    if (int(locations[a[0]].size()) < k || int(locations[a[n - 1]].size()) < k) {
        cout << "NO\n";
        return;
    }

    int l = locations[a[0]][k - 1], r = locations[a[n - 1]][locations[a[n - 1]].size() - k];
    cout << ((l < r) ? "YES\n" : "NO\n");
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
