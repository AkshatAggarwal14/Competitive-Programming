#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll sum_alice = 0, sum_bob = 0, pre_alice = 0, pre_bob = 0;
    ll moves = 0;
    ll l = 0, r = n - 1;
    while (l <= r) {
        if (moves % 2 == 0) {
            pre_alice = 0;
            while (l <= r && pre_alice <= pre_bob) {
                pre_alice += a[l];
                sum_alice += a[l];
                l++;
            }
        } else {
            pre_bob = 0;
            while (l <= r && pre_bob <= pre_alice) {
                pre_bob += a[r];
                sum_bob += a[r];
                r--;
            }
        }
        moves++;
    }
    cout << moves << ' ' << sum_alice << ' ' << sum_bob << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}