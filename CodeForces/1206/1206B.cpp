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
    ll n, ans = 0, p = 1, c_0 = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
        if (x >= 1) ans += (x - 1), x = 1;
        if (x <= -1) ans += (-1 - x), x = -1;
        if (x == 0) ans++, ++c_0, x = 1;
        p *= x;
    }
    if (p == 1 || c_0) return void(cout << ans << '\n');
    cout << ans + 2 << '\n';
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