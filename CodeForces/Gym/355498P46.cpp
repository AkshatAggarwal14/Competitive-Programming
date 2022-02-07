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

set<ll> vals;
void fill() {
    ll a = 1, b = 1, c = a + b;
    vals.insert(a);
    vals.insert(a + b);
    while (c < 1000) {
        vals.insert(c);
        a = b;
        b = c;
        c = a + b;
    }
}

void Solution() {
    ll n;
    cin >> n;
    string ans(n, 'o');
    for (ll i = 0; i < n; ++i)
        if (vals.contains(i + 1)) ans[i] = 'O';
    cout << ans << '\n';
}

// clang-format off
int main() {
    fill();
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