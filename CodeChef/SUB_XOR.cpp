#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
const ll INF = 1e18;

/*
abcd
abcd
abcd
abcd

make triangles, for each corresponding bit and see what is in it.
ans = [a a+2b a+2b+3c a+2b+3c+4d]
*/

void Solution() {
    ll n;
    string s;
    cin >> n >> s;
    string ans(s);
    ll sum = 0, term = 0;
    for (ll i = 0; i < n; ++i) {
        ++term;
        sum += term * (s[i] - '0');
        ans[i] = char(sum % 2) + '0';
    }
    ll res = 0;
    reverse(all(ans));
    ll p = 1;
    for (ll i = 0; i < n; ++i) {
        res += (p * (ans[i] - '0'));
        res %= MOD;
        p *= 2;
        p %= MOD;
    }
    cout << res << '\n';
    // dbg(ans);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}