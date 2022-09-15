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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) cin >> a[i], pos[a[i]].push_back(i);
    auto b = a;
    int far = -1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) {
            far = max(far, pos[a[i]].back());
            for (auto &j : pos[a[i]]) a[j] = 0;
        }
    }
    set<int> diff;
    for (int i = 0; i <= far; ++i) diff.insert(b[i]);
    cout << sz(diff) << '\n';
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
