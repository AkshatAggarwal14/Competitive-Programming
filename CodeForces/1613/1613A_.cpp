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
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    string s1 = to_string(x1), s2 = to_string(x2);
    ll mx = max(sz(s1), sz(s2));
    ll zeroes1 = mx - sz(s1), zeroes2 = mx - sz(s2);
    s1.append(string(zeroes1, '0'));
    s2.append(string(zeroes2, '0'));
    p1 -= zeroes1, p2 -= zeroes2;
    if (s1 == s2) {
        if (p1 == p2) return void(cout << "=\n");
        if (p1 < p2) return void(cout << "<\n");
        return void(cout << ">\n");
    }
    if (s1 < s2) {
        if (p1 <= p2) return void(cout << "<\n");
        return void(cout << ">\n");
    }
    // s1 > s2
    if (p2 <= p1) return void(cout << ">\n");
    return void(cout << "<\n");
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