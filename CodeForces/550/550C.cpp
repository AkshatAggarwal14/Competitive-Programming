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
    string s;
    cin >> s;
    for (ll c = 0; c < 1000; c += 8) {  // as last 3 digits must be divisible by 8
        string t = to_string(c);
        ll pos = 0;
        for (ll i = 0; i < sz(s); ++i) {
            if (s[i] == t[pos] && pos < sz(t)) pos++;
            if (pos != sz(t)) continue;
            cout << "YES\n";
            cout << t;
            return;
        }
    }
    cout << "NO\n";
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