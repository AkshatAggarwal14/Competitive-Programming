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

ll LIS(vector<ll> &arr) {
    vector<ll> dp;
    ll n = ll(arr.size());
    for (ll i = 0; i < n; i++) {
        // upper_bound for Longest Non Decreasing Subsequence
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
            dp.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    return ll(dp.size());
}

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll &A : a) cin >> A;
    for (ll &B : b) cin >> B;
    cout << LIS(a) + LIS(b) << '\n';
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