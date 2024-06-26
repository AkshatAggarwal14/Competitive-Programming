#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll i = n - 1;
    vector<string> ans;
    while (i > 0) {
        if (s[i] == 'a' or s[i] == 'e') {
            // VC
            ans.push_back(s.substr(i - 1, 2));
            i -= 2;
        } else {
            // CVC
            ans.push_back(s.substr(i - 2, 3));
            i -= 3;
        }
    }
    ll sz = ll(ans.size());
    reverse(ans.begin(), ans.end());
    for (ll j = 0; j < sz; ++j) {
        if (j != 0) cout << '.';
        cout << ans[j];
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
