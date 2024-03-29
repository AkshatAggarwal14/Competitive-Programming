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
    string s;
    cin >> n >> s;

    ll score = 0;
    for (int i = 0; i < n; ++i)
        score += ((s[i] == 'R') ? (n - 1 - i) : (i));

    vector<ll> ans;

    auto increase = [&](ll id) {
        score -= id;
        score += n - 1 - id;
        ans.push_back(score);
    };

    for (ll i = 0; i < n / 2; ++i) {
        if (s[i] == 'L') increase(i);
        if (s[n - 1 - i] == 'R') increase(i);
    }
    while (sz(ans) != n) ans.push_back(score);
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
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
