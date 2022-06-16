#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return ll(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s;
    cin >> s;
    vector<string> choices;
    for (ll i = 1; i * i <= ll(2e9); ++i) choices.push_back(to_string(i * i));
    ll ans = INF;
    for (auto &choice : choices) {
        if (sz(choice) > sz(s)) break;
        ll pos = 0;
        for (ll i = 0; i < sz(s); ++i)
            if (s[i] == choice[pos]) pos++;
        if (pos == sz(choice)) ans = min(ans, sz(s) - sz(choice));
    }
    if (ans == INF) ans = -1;
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
