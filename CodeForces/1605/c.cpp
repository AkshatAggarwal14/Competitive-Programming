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
    vector<string> vv = {"aa", "aba", "aca", "acba", "abca", "abbacca", "accabba"};  // all possible cases a -- a -- a <- cant have more such cases
    ll ans(LLONG_MAX);
    ll n;
    string s;
    cin >> n >> s;
    for (string &op : vv) {
        if (sz(op) > sz(s)) break;
        if (s.find(op) != string::npos) amin(ans, sz(op));
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
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