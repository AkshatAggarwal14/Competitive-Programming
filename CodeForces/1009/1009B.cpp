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
    // 1s can be moved anywhere.
    string ans = "", ones = "";
    for (char &c : s) (c != '1' ? ans : ones) += c;
    ll it = -1;
    for (ll i = 0; i < sz(ans); ++i) {
        if (ans[i] == '2') {
            it = i;
            break;
        }
    }
    if (it == -1) {
        cout << ans << ones << '\n';
    } else {
        cout << ans.substr(0, it) << ones << ans.substr(it) << '\n';
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
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}