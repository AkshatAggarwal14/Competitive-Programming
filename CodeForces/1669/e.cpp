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
    vector<string> a(n);
    vector<vector<ll>> cnt(26, vector<ll>(26, 0));

    auto count = [&](string s) -> ll & { return cnt[s[0] - 'a'][s[1] - 'a']; };

    for (ll i = 0; i < n; ++i) cin >> a[i], ++count(a[i]);
    ll ans = 0;
    string t;
    for (ll i = 0; i < n; ++i) {
        string &s = a[i];
        if (count(s)) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != s[0]) {
                    t = "";
                    t += c;
                    t += s[1];
                    if (count(t)) ans += count(s) * count(t);
                }
                if (c != s[1]) {
                    t = "";
                    t += s[0];
                    t += c;
                    if (count(t)) ans += count(s) * count(t);
                }
            }
            count(s) = 0;
        }
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
