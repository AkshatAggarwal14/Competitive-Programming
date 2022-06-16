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
    // b1 = a1 + n * a2 + (n - 1) * a3..... (2) * an
    // b2 = 2 * a1 + a2 + n * a3.... 3 * an
    // b3 = 3 * a1 + 2 * a2 + a3 ........ 4 * an
    // bn = n * a1 + (n - 1) * a2 + ... + an
    //! b1 - bn = a_sum - n * a1
    //! b2 - b1 = a_sum - n * a2, same for b3..
    ll n;
    cin >> n;
    vector<ll> b(n), a(n);
    for (ll &x : b) cin >> x;
    ll b_sum = accumulate(all(b), 0LL);
    b_sum *= 2;
    ll div = n * (n + 1);
    if (b_sum % div) return void(cout << "NO\n");
    ll a_sum = b_sum / div;
    for (ll i = 0; i < n; i++) {
        a[i] = a_sum - b[i] + b[(n + i - 1) % n];
        if (a[i] % n || a[i] < 1 || a[i] > (ll)1e9) return void(cout << "NO\n");
        a[i] /= n;
    }
    cout << "YES\n";
    for (ll &x : a) cout << x << ' ';
    cout << '\n';
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