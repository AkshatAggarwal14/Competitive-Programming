#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

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

ll reversed(ll n) {
    string bin = toBinary(n);
    while (bin.back() == '0') bin.pop_back();
    reverse(all(bin));
    return toDecimal(bin);
}

ll x, y;
set<ll> vals;
void recurse(ll cx) {
    if (cx > (ll)6e18) return;
    if (vals.count(cx) || vals.count(y)) return;
    vals.insert(cx);
    recurse(reversed(cx));
    recurse(reversed(cx * 2 + 1));
}

void Solution() {
    cin >> x >> y;
    recurse(x);
    cout << ((vals.count(y)) ? "YES\n" : "NO\n");
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}
