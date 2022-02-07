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

vector<ll> a(17);
ll check(ll L, ll R) {
    if (L >= R) return 1;
    bool flag = true;
    for (ll i = L; i < R; ++i)
        if (a[i] > a[i + 1]) flag = false;
    if (flag) return (R - L + 1);
    return max(check(L, (R + L - 1) / 2), check((R + L - 1) / 2 + 1, R));
}

void Solution() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    cout << check(1LL, n);
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