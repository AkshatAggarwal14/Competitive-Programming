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
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(all(a));
    ll q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        ll L = -1, R = n, i1, i2;
        while (R > L + 1) {
            ll m = (L + R) / 2;
            (a[m] < l ? L : R) = m;
        }
        i1 = R;
        L = -1, R = n;
        while (R > L + 1) {
            ll m = (L + R) / 2;
            (a[m] <= r ? L : R) = m;
        }
        i2 = L;
        dbg(i1, i2);
        cout << i2 - i1 + 1 << '\n';
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