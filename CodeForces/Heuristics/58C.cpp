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

bool isNum(const char &c) {
    return (c >= '0' && c <= '9');
}

bool isChar(const char &c) {
    return (c >= 'a' && c <= 'z');
}

void Solution() {
    string s;
    ll a, b, ans = LLONG_MAX;
    cin >> s >> a >> b;
    for (char ch = '0'; ch <= '9'; ++ch) {
        ll cost = 0;
        for (ll i = 0; i < sz(s); ++i) {
            if (isChar(s[i])) cost += a;
            if (isNum(s[i]) && s[i] != ch) cost += b + a;
        }
        amin(ans, cost);
    }
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        ll cost = 0;
        for (ll i = 0; i < sz(s); ++i) {
            if (isChar(s[i]) && s[i] != ch) cost += a + b;
            if (isNum(s[i])) cost += b;
        }
        amin(ans, cost);
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}