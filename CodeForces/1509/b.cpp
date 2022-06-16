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
    ll n;
    string s;
    cin >> n >> s;
    ll T = count(all(s), 'T'), M = count(all(s), 'M');
    if (2 * M != T) return void(cout << "NO\n");
    set<ll> firstT, lastT, m;
    for (ll i = 0; i < n; ++i)
        (s[i] == 'T' ? ((sz(firstT) == T / 2) ? lastT : firstT) : m).insert(i);
    while (!firstT.empty() && !lastT.empty() && !m.empty()) {
        auto i1 = firstT.begin();          // first possible T
        auto i2 = m.begin();               // first possible M
        auto i3 = lastT.lower_bound(*i2);  // first possible T after M
        if (i2 != m.end() && *i2 > *i1 && *i3 > *i2) {
            firstT.erase(*i1), m.erase(*i2), lastT.erase(*i3);
        } else {
            return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
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