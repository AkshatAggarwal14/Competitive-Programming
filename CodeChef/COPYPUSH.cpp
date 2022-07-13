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
    string s;
    cin >> n >> s;
    function<bool(ll, ll)> dfs = [&](ll l, ll r) {
        if (l > r) return false;
        if (r <= l + 1) return s[l] == s[r];
        ll len = r - l + 1;
        if (len & 1) {
            return dfs(l, r - 1);
        } else {
            if (s.substr(l, len / 2) != s.substr(l + len / 2, len / 2))
                return false;
            else
                return dfs(l, l + len / 2 - 1);
        }
    };
    cout << (dfs(0, n - 1) ? "YES\n" : "NO\n");
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
