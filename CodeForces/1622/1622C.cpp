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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), pref(n, 0);
    for (ll &A : a) cin >> A;
    sort(all(a));
    partial_sum(all(a), pref.begin());
    ll steps = LLONG_MAX;
    for (ll i = 0; i < n; ++i) {
        ll sum_before = pref[i] - a[0];  // sum of elements before & including i except a[0]
        ll left_sum = k - sum_before;    // sum of remaining elements so total <= k
        // to_make is the minimum value of n - i elements needed so sum <= k
        ll to_make = min(a[0], ll(floor(double(left_sum) / double((n - i)))));
        // STEPS = reduce minimum element to some value + set other n - i - 1 to that value = n
        amin(steps, (a[0] - to_make) + (n - i - 1));
    }
    cout << steps << '\n';
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