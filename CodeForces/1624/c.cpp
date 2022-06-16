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
    for (ll &A : a) cin >> A;
    sort(all(a));
    set<ll> put;
    for (ll i = 0; i < n; ++i) {
        ll t = a[i];
        while (t) {
            if (t >= 1 && t <= n && !put.count(t)) {
                put.insert(t);
                break;
            }
            t /= 2;
        }
        if (t == 0) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

//! -----------------------------------------------------------------------------

void Better() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(n + 1, 0);
    for (ll &A : a) {
        cin >> A;
        while (A > n) A /= 2;
        ++cnt[A];
    }
    for (ll i = n; i >= 1; --i) {
        if (cnt[i] == 0) return void(cout << "NO\n");
        cnt[i / 2] += (cnt[i] - 1);  // use 1, add rest
    }
    cout << "YES\n";
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
        // Solution();
        Better();
    }
    return 0;
}