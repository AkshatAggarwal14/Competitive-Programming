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
    // unequal indexes in sorted - observation
    ll n;
    string s, s1;
    cin >> n >> s;
    s1 = s;
    ranges::sort(s1);
    vector<ll> vals;
    for (ll i = 0; i < n; ++i)
        if (s1[i] != s[i]) vals.push_back(i + 1);
    if (vals.empty()) return void(cout << 0 << '\n');
    cout << 1 << '\n';
    cout << sz(vals) << ' ';
    for (auto &x : vals) cout << x << ' ';
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