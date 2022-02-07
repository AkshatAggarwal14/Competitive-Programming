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
    ll n;
    string s;
    cin >> n >> s;
    ll c0 = count(all(s), '0'), c1 = n - c0;
    string ans = "";
    for (ll i = 0; i < n && c1 && c0; ++i) {
        if (i % 2 == 0) {
            ans += '1';
            --c1;
        } else {
            ans += '0';
            --c0;
        }
    }
    while (c0--) ans += '0';
    while (c1--) ans += '1';
    ll ctr = 0;
    for (ll i = 0; i < n - 3; ++i)
        if (ans.substr(i, 4) == "1010") ctr++;
    cout << ctr << '\n';
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