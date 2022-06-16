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

/*
    c**2 = a**2 + b**2
    c = a**2 - b
    Thus, c * (c - 1) == b * (b + 1) --> c = b + 1
    Let a = n
    c = n**2 - b = n**2 - (c - 1)
    c = (n**2 + 1)/2
    b = (n**2 - 1)/2
    (a, b, c) === (n, (n**2 - 1)/2, (n**2 + 1)/2), all <= n
*/

void Solution() {
    ll n, ctr = 0;
    cin >> n;
    for (ll i = 1; (i * i + 1) / 2 <= n; ++i) {
        ll a = i, b = ((i * i) - 1) / 2, c = ((i * i) + 1) / 2;
        if (((i * i) & 1) && a <= b && b <= c && c <= n) ctr++;
    }
    cout << ctr << '\n';
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