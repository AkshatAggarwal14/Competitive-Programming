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
    ll n, m;
    cin >> n >> m;
    ll mn = min(n, m);
    string s = "";
    for (ll i = 0; i < mn + 1; ++i) s += '0', s += '1';  // 010101.. EQUAL
    n -= mn, m -= mn;
    if (n) {  // handle remaining seperately
        s += '0', n--;
        while (n--) s += "010";
    } else if (m) {
        s = "1" + s, m--;
        while (m--) s = "101" + s;
    }
    cout << sz(s) << '\n';
    cout << s << '\n';
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