#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

void Solution() {
    string a, s;
    cin >> a >> s;
    reverse(all(a));
    reverse(all(s));
    string b = "";
    ll pos = 0;
    for (ll i = 0; i < sz(a); ++i) {
        if (s[pos] < a[i]) {  // if smaller take 2 digits at a time
            if (pos >= sz(s)) return void(cout << "-1\n");
            if (pos + 1 >= sz(s)) return void(cout << "-1\n");
            ll num = (s[pos] - '0') + (s[pos + 1] - '0') * 10;
            num -= (a[i] - '0');
            if (!(num >= 0 && num <= 9)) return void(cout << "-1\n");
            b += (char(num) + '0');
            pos += 2;
        } else {  // else go through digits one by one
            if (pos >= sz(s)) return void(cout << "-1\n");
            ll num = (s[pos] - '0');
            num -= (a[i] - '0');
            if (!(num >= 0 && num <= 9)) return void(cout << "-1\n");
            b += (char(num) + '0');
            pos++;
        }
    }
    while (pos < sz(s)) b += s[pos++];     // add remaining digits of s
    while (b.back() == '0') b.pop_back();  // remove all zeroes from front
    reverse(all(b));
    cout << b << '\n';
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