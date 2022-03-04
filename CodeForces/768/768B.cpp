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
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

/*
    10 -> 5 -> 2 -> 1
/2  5 -> 2 -> 1 -> 0
%2  [0 -> 1 -> 0] -> 1

    0 -> 1 -> 0 -> 1 // the last num here is 0 for 0, 1 for everything else
j = 3    2    1    0
    for a given index i with highest set bit j, it uses the answer for jth level.
*/

string toBinary(ll n) {
    string s = bitset<64>(n).to_string();
    const auto pos = s.find('1');
    if (pos != string::npos) return s.substr(pos);
    return "0";
}

ll toDecimal(string s) {
    ll res = 0, temp = 1;
    for (ll i = ll(s.size()) - 1LL; i >= 0; i--) {
        if (s[i] == '1') res += temp;
        temp *= 2;
    }
    return res;
}

void Solution() {
    ll n, l, r;
    cin >> n >> l >> r;
    ll ans = 0;
    string s(toBinary(n));
    for (ll i = l; i <= r; ++i) {
#ifdef MANUAL
        ll lsb = -1;
        for (ll j = 0; j <= 49; ++j)
            if (i & (1LL << j)) {
                lsb = j;
                break;
            }
        if (lsb != -1) ans += s[lsb] - '0';
#else
        ll lsb = (i & (~(i - 1)));
        if (i != 0) ans += s[__lg(lsb)] - '0';
#endif
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}