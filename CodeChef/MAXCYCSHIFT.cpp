#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        a.push_back(a[i]);
    }
    vector<int> pre(2 * n + 1);
    for (int i = 0; i < 2 * n; ++i) {
        pre[i + 1] = (pre[i] ^ a[i]);
    }
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        mp[pre[i]]++;
    }
    int ans = mp.size();
    for (int i = n + 1; i <= 2 * n; ++i) {
        mp[pre[i - n]]--;
        if (mp[pre[i - n]] == 0) {
            mp.erase(pre[i - n]);
        }
        mp[pre[i]]++;
        ans = max(ans, (int)mp.size());
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
