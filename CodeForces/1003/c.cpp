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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), pref(n + 1, 0);
    double res = 0;
    for (ll &x : a) cin >> x;
    partial_sum(all(a), 1 + pref.begin());
    for (ll r = 0; r < n; ++r)
        for (ll l = 0; l <= r; ++l)
            if (r - l + 1 >= k)
                amax(res, double(pref[r + 1] - pref[l]) / double(r - l + 1));
    cout << res << '\n';
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