#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pos(n + 1);
    vector<int> f(n + 1), b(m + 1);
    for (int i = 1; i <= n; ++i) cin >> f[i], pos[f[i]].push_back(i);
    for (int i = 1; i <= m; ++i) cin >> b[i];
    vector<int> a(m + 1, -1);
    bool amb = false, imp = false;
    for (int i = 1; i <= m; ++i) {
        int val = b[i];
        if (pos[val].size() >= 2) {
            amb = true;
        } else if (pos[val].size() == 0) {
            imp = true;
        } else {
            a[i] = pos[val][0];
        }
    }
    if (imp) return void(cout << "Impossible\n");
    if (amb) return void(cout << "Ambiguity\n");
    cout << "Possible\n";
    for (int i = 1; i <= m; ++i) cout << a[i] << " \n"[i == m];
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
