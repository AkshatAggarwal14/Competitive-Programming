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
    cin >> n;
    vector<ll> b(n), a(n);
    for (auto &x : b) cin >> x;
    a[0] = b[0];
    for (ll i = 1; i < n; ++i) {
        ll curr = b[i], prev = b[i - 1];
        if ((curr > prev) || (prev % curr != 0)) return void(cout << -1 << '\n');
        // find a number divisible by cur but not prev
        a[i] = a[i - 1] / (prev / curr);
    }
    for (auto &x : a) cout << x << ' ';
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