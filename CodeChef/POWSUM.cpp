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
    // X * A + left = two
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll S = accumulate(all(a), 0LL);
    if (__builtin_popcount(uint32_t(S)) == 1) return void(cout << "0\n");
    for (ll i = 0; i < n; ++i) {
        ll A = a[i];
        ll left = S - a[i];
        for (ll j = 1; j <= 50; ++j) {
            ll Ans = (1LL << j);
            if (Ans > left && (Ans - left) % A == 0) {
                ll X = (Ans - left) / A;
                if (X > (1LL << 30)) continue;
                cout << "1\n";
                cout << "1 " << X << '\n';
                cout << i + 1 << '\n';
                return;
            }
        }
    }
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