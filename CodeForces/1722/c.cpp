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
    map<string, vector<int>> mp;
    int n;
    cin >> n;
    string t;
    for (int j = 0; j < 3; ++j)
        for (int i = 0; i < n; ++i) cin >> t, mp[t].push_back(j);
    vector<int> score(3);
    for (auto &[x, y] : mp) {
        if (sz(y) == 1) {
            score[y[0]] += 3;
        } else if (sz(y) == 2) {
            score[y[0]] += 1;
            score[y[1]] += 1;
        }
    }
    for (auto &x : score) cout << x << ' ';
    cout << '\n';
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
