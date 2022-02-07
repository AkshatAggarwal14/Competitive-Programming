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

bool check(const vector<ll> &a) {
    ll n = sz(a);
    for (ll l = 0; l < n; ++l) {
        for (ll r = l; r < n; ++r) {
            ll XOR = 0;
            for (ll i = l; i <= r; ++i) {
                XOR ^= a[i];
            }
            if (XOR == 0) return false;
        }
    }
    return true;
}

//https://www.geeksforgeeks.org/find-array-such-that-no-subarray-has-xor-zero-or-y/
void Solution() {
    ll n;
    cin >> n;
    vector<ll> a;
    for (ll i = 1; i <= n; ++i) a.push_back(i ^ (i - 1));
    for (ll &A : a) cout << A << ' ';
    cout << '\n';
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