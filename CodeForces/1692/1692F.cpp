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
    ll n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> cnt(10, 0);
    for (auto &it : a) cin >> it, it %= 10, ++cnt[it];
    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            for (int k = j; k < 10; ++k) {
                if ((i + j + k) % 10 == 3) {
                    int x = cnt[i], y = cnt[j], z = cnt[k];
                    int res = 0;
                    if (cnt[i] > 0) --cnt[i], ++res;
                    if (cnt[j] > 0) --cnt[j], ++res;
                    if (cnt[k] > 0) --cnt[k], ++res;
                    if (res == 3) {
                        cout << "YES\n";
                        return;
                    } else {
                        cnt[i] = x, cnt[j] = y, cnt[k] = z;
                    }
                }
            }
        }
    }
    cout << "NO\n";
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
