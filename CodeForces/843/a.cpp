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

template <class T>
vector<int> coordinateCompress(const vector<T> &a) {
    int n = int(a.size());

    vector<pair<T, int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = {a[i], i};
    sort(v.begin(), v.end());
    vector<int> res(n);
    int curr = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            ++curr;
        }
        res[v[i].second] = curr;
    }
    return res;
}

void test() {
    int n;
    cin >> n;
    vector<int> a(n), pos(n);
    for (auto &x : a) cin >> x;
    a = coordinateCompress(a);
    for (int i = 0; i < n; ++i) pos[a[i]] = i;
    vector<bool> vis(n, false);
    vector<vector<int>> cycles;
    vector<int> cycle;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        cycle.clear();
        int j = i;
        while (!vis[j]) {
            cycle.push_back(j + 1);
            vis[j] = true;
            j = pos[j];
        }
        cycles.push_back(cycle);
    }
    cout << cycles.size() << '\n';
    for (auto &c : cycles) {
        cout << c.size() << ' ';
        for (auto &e : c) cout << e << ' ';
        cout << '\n';
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
