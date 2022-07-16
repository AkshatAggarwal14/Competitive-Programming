#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<ll> len;
    len.push_back(n);
    vector<array<ll, 2>> Q(c);
    for (auto &[x, y] : Q) cin >> x >> y, --x, --y, len.push_back(y - x + 1);
    for (int i = 1; i < int(len.size()); ++i) len[i] += len[i - 1];
    while (q--) {
        ll id;
        cin >> id;
        while (id > n) {
            auto i = lower_bound(len.begin(), len.end(), id) - len.begin();
            id = id - len[i - 1] + Q[i - 1][0];
        }
        cout << s[id - 1] << '\n';
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
