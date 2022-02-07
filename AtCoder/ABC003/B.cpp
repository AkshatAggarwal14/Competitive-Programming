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
    string s1, s2, s = "atcoder";
    cin >> s1 >> s2;
    for (ll i = 0; i < sz(s1); ++i) {
        if (s1[i] == s2[i]) continue;
        if ((s1[i] == '@' && s.find(s2[i]) != string::npos) || (s2[i] == '@' && s.find(s1[i]) != string::npos)) s1[i] = s2[i] = '@';
    }
    if (s1 == s2)
        cout << "You can win\n";
    else
        cout << "You will lose\n";
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