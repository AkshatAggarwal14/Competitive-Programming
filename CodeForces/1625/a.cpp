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
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll res = 0;
    for (ll i = l - 1; i >= 0; i--) {
        ll cnt = 0;
        for (ll j = 0; j < n; j++)
            if (a[j] & (1LL << i)) cnt++;
        if (2 * cnt > n) res += (1LL << i);
    }
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}