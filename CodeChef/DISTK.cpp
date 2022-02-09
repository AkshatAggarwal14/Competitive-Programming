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

/*
check position of 1 in []

1 1 1 1 [1] = 5 + 0
1 1 1 [1 2] = 5 + 1
1 1 1 [2 1]
1 1 [1 2 3] = 5 + 3
1 1 [2 1 3]
1 1 [2 3 1]
1 [1 2 3 4] = 5 + 6
1 [2 1 3 4]
1 [2 3 1 4]
1 [2 3 4 1]
[1 2 3 4 5] = 5 + 10
*/

void Solution() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 1);
    ll left = k - n, X = -1;
    for (ll i = 0; i < n; ++i) {
        if (i * (i + 1) / 2 > left) break;
        X = i;
    }
    ll start = X;
    ll diff = start - (left - start * (start + 1) / 2);
    ll idx_1 = n - 1 - diff;
    ll cnt = 2;
    for (ll i = n - 1 - (start); i < n; ++i) {
        if (i == idx_1) {
            a[i] = 1;
        } else {
            a[i] = cnt++;
        }
    }
    for (ll &A : a) cout << A << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}