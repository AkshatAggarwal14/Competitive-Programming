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
    int n, k;
    cin >> n >> k;
    if (k % 4 == 0) return void(cout << "NO\n");
    k %= 4;
    cout << "YES\n";
    vector<vector<int>> vals(4);
    for (int i = 1; i <= n; ++i) vals[i % 4].push_back(i);
    if (k == 2) swap(vals[1], vals[2]);
    for (int i = 0; i < sz(vals[0]); ++i) cout << vals[3][i] << ' ' << vals[0][i] << '\n';
    for (int i = 0; i < sz(vals[1]); ++i) cout << vals[1][i] << ' ' << vals[2][i] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
