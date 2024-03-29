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
    ll sum = 0;
    for (auto &x : s) sum += ll(x - '0');
    string ans;
    reverse(s.begin(), s.end());

    ll carry = 0;
    // dbg(sum, carry);
    for (auto &x : s) {
        ll dig = (sum % 10 + carry);
        // dbg(dig);

        ans.push_back(char(dig % 10 + '0'));
        if (dig >= 10) {
            carry = sum / 10 + dig / 10;
        } else {
            carry = sum / 10;
        }

        sum -= ll(x - '0');
        // dbg(sum, dig, ans, carry);
    }

    // dbg(carry, sum);
    reverse(ans.begin(), ans.end());

    if (carry > 0)
        ans = to_string(carry) + ans;

    reverse(ans.begin(), ans.end());

    while (!ans.empty() and ans.back() == '0') {
        ans.pop_back();
    }

    if (ans.empty()) ans = '0';

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
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
