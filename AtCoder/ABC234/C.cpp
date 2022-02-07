#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

// 2 "extra"
/*
      extra
       ""
   0       2
00  02  20  22
...
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
    ll k;
    cin >> k;
    string ans(toBinary(k));
    for (auto &x : ans)
        if (x == '1') x = '2';
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}