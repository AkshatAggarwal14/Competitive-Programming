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
    ll g1 = a[0];
    for (ll i = 0; i < n; i += 2) g1 = gcd(g1, a[i]);
    for (ll i = 1; i < n; i += 2) {
        if (a[i] % g1 == 0) {
            ll g2 = a[1];
            for (ll j = 1; j < n; j += 2) g2 = gcd(g2, a[j]);
            for (ll j = 0; j < n; j += 2) {
                if (a[j] % g2 == 0) return void(cout << "0\n");
            }
            return void(cout << g2 << '\n');
        }
    }
    cout << g1 << '\n';
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