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
    string s, t;
    cin >> n >> s >> t;
    auto isVowel = [](const char &c) -> bool {
        return ((c == 'a') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'e'));
    };
    auto calculate = [&](const string &S, const string &T) {
        ll res = 0;
        for (ll i = 0; i < n; ++i)
            if (S[i] != T[i]) res += ((isVowel(S[i]) ^ isVowel(T[i])) ? 1 : 2);
        return res;
    };
    ll ans = sz(s);  // max possible ans
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        string sNew = "", tNew = "";
        for (ll i = 0; i < n; ++i)  // make new strings
            sNew += ((s[i] == '?') ? ch : s[i]), tNew += ((t[i] == '?') ? ch : t[i]);
        amin(ans, calculate(sNew, tNew));  // O(26 * n)
        if (ans == 0) break;               // min possible
    }
    cout << ans << '\n';
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