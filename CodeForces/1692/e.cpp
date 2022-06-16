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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    if (accumulate(all(a), 0) < s) return void(cout << "-1\n");
    vector<int> pref(n + 1);
    partial_sum(all(a), 1 + pref.begin());
    auto get = [&](int i, int j) { return pref[j + 1] - pref[i]; };
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int L = i, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            int mid = (L + R) / 2;
            if (get(i, mid) <= s) {
                L = mid;
            } else {
                R = mid;
            }
        }
        if (get(i, L) == s) ans = min(ans, n - (L - i + 1));
    }
    cout << ans << '\n';
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
