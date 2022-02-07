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

void Solution() {
    ll n;
    string s;
    cin >> n >> s;
    auto winner = [&](char c1, char c2) -> char {
        if (c1 == c2) return c1;
        if ((c1 == 'R' && c2 == 'S') || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'R')) return c1;
        return c2;
    };
    string ans = "";
    for (ll start = 0; start < n; ++start) {
        char win = s[start];
        for (ll j = start; j < n; ++j) win = winner(win, s[j]);
        ans += win;
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