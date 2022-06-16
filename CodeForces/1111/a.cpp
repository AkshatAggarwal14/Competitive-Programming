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

bool isVowel(const char &ch) { return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); }

void Solution() {
    string s, t;
    cin >> s >> t;
    if (sz(s) != sz(t)) return void(cout << "No\n");
    for (ll i = 0; i < sz(s); ++i)
        if (isVowel(s[i]) ^ isVowel(t[i])) return void(cout << "No\n");
    cout << "Yes\n";
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