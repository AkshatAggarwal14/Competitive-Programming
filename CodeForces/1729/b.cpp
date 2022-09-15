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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    reverse(all(s));
    for (ll i = 0; i < n;) {
        if (s[i] == '0') {
            char c1 = s[i + 1], c2 = s[i + 2];
            int num = (c2 - '0') * 10 + (c1 - '0');
            ans += (num - 1 + 'a');
            i += 3;
        } else {
            ans += ((s[i] - '0') - 1 + 'a');
            ++i;
        }
    }
    reverse(all(ans));
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
