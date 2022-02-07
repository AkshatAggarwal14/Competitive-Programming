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
    string s, t;
    cin >> s >> t;
    ll n = sz(s), ca = 0, cb = 0, cc = 0;
    sort(all(s));
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'a')
            ca++;
        else if (s[i] == 'b')
            cb++;
        else if (s[i] == 'c')
            cc++;
    }
    if ((!(t[0] == 'a' && t[1] == 'b')) || (!(cb && cc && ca))) return void(cout << s << '\n');
    string res = "";
    res.append(string(ca, 'a'));
    res.append(string(cc, 'c'));
    res.append(string(cb, 'b'));
    cout << res;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c') continue;
        cout << s[i];
    }
    cout << '\n';
}

// ------------------------------------------------------------------------------
void Better() {
    string s, t;
    cin >> s >> t;
    sort(all(s));
    if (t == "abc" && count(all(s), 'a')) {
        sort(all(s), [&](char a, char b) {
            if (a == 'b' and b == 'c') return false;
            if (a == 'c' and b == 'b') return true;
            return a < b;
        });
        cout << s << '\n';
    } else {
        cout << s << '\n';
    }
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
    Better();
    // Solution();
    return 0;
}