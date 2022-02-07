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

const ll mod = 1000000007;

void Solution() {
    int x, y, n;
    cin >> x >> y >> n;
    //x, y, y - x,  - x,  - y, x - y
    int a[6];
    a[0] = x;
    a[1] = y;
    a[2] = y - x;
    a[3] = -a[0];
    a[4] = -a[1];
    a[5] = -a[2];
    int m = (n % 6) - 1;
    if (m == -1) m = 5;  //if n%6==0
    int ans = a[m] % mod;
    if (a[m] >= 0)
        cout << ans;
    else
        cout << (mod + ans) % mod;
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