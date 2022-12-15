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
    string s, t;
    cin >> n >> s >> t;
    vector<pair<ll, ll>> ans;
    // make s = 0000 and t should then be either 0000 or 1111
    ll c1 = count(all(s), '1');
    string T;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') ans.push_back({i, i});
        if ((c1 - (s[i] - '0')) & 1) {
            // total operations - operation at this point = odd
            // because t[i] isnt modified on operation {i, i}
            // flipped when odd
            T += ((t[i] == '0') ? '1' : '0');
        } else {
            T += t[i];
        }
    }
    if (T == string(n, '1')) {
        ans.push_back({0, n - 1});
        ans.push_back({0, 0});
        ans.push_back({1, n - 1});
    } else if (T == string(n, '0')) {
    } else {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << sz(ans) << '\n';
    for (auto &[x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
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
