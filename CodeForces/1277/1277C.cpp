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
    // one -> remove n
    // two -> remove w
    // twone -> remove o
    string s;
    cin >> s;
    vector<ll> ans;
    for (ll i = 0; i < sz(s); ++i) {
        if (i + 4 < sz(s) && s.substr(i, 5) == "twone") {
            ans.push_back(i + 3);
            i += 4;
        } else if (i + 2 < sz(s) && (s.substr(i, 3) == "two" || s.substr(i, 3) == "one")) {
            ans.push_back(i + 2);
            i += 2;
        }
    }
    cout << sz(ans) << '\n';
    for (ll &i : ans) cout << i << ' ';
    cout << '\n';
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