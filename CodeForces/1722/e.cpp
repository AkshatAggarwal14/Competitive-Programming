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

const ll MX = 1000;
void test() {
    int n, q;
    cin >> n >> q;
    using pi = pair<int, int>;
    vector<pi> a(n);
    vector<vector<ll>> HW(MX + 1, vector<ll>(MX + 1, 0));
    for (auto &[x, y] : a)
        cin >> x >> y, HW[x][y] += x * y;

    vector<vector<ll>> pref(MX + 1, vector<ll>(MX + 1, 0));
    for (int i = 1; i <= MX; i++)
        for (int j = 1; j <= MX; j++)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                         HW[i][j];
    auto get = [&](ll x1, ll y1, ll x2, ll y2) {
        if (x1 > x2 || y1 > y2) return 0LL;
        return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
    };

    while (q--) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        cout << get(h1 + 1, w1 + 1, h2 - 1, w2 - 1) << '\n';
    }
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
