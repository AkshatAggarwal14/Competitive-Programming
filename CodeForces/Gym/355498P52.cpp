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
    vector<set<ll>> pos(1e6 + 1);
    for (ll i = 0; ll & x : a) cin >> x, pos[x].insert(i++);
    ll mx = -1;
    for (auto &x : pos) amax(mx, sz(x));
    ll L, R, len = n;
    for (auto &x : pos) {
        if (sz(x) == mx) {
            if (amin(len, *x.rbegin() - *x.begin())) {
                L = *x.begin();
                R = *x.rbegin();
            }
        }
    }
    cout << L + 1 << ' ' << R + 1 << '\n';
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