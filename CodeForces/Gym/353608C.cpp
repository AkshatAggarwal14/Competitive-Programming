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
    if (n < 3) return void(cout << -1);
    if (n == 3) return void(cout << 210);
    //! runtime
    // idea -> every 210 numbers have 1 divisible by 210
    // BigInt L("1" + string(n - 1, '0'));
    // BigInt R("1" + string(n - 4, '0') + "210");
    // for (BigInt i = L; i <= R; i = i + 1) {
    //     if (i % 210 == 0) {
    //         cout << i << '\n';
    //         break;
    //     }
    // }
    vector<ll> rem = {170, 20, 200, 110, 50, 80};  // rN+ 10^(N-1), rN is cycle of length 6
    string left = to_string(rem[n % 6]);
    string ans = "1" + string(n - sz(left) - 1, '0') + left;
    cout << ans << '\n';
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