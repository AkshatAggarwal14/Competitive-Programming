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

// returns last i in [l, r], p(i) true, and if none found, returns l - 1
ll find_last_true(ll l, ll r, const auto &pred) {
    --l, ++r;
    for (ll m; m = l + (r - l) / 2, r > l + 1;) (pred(m) ? l : r) = m;
    return l;
}

/* 
i -> groupsBefore
k -> indexInGroup (1 - based)

i   s           k
0
    aaabb +     1
1
    aabab       1
    aabba +     2
2
    abaab       1
    ababa       2
    abbaa +     3
3
    baaab       1
    baaba       2
    babaa       3
    bbaaa +     4
1 + 2 + ... n - 1 -> n*(n-1)/2 = n!/(n-2)!*2!
b1 = n - 2 - i // ith group
b2 = n - 1 - k // kth string in ith group
*/

void Solution() {
    ll n, k, b1 = 0, b2 = 0;
    cin >> n >> k;
    ll groupsBefore = find_last_true(1LL, n - 1, [&](ll m) { return (m * (m + 1)) / 2 < k; });  // num of groups before k
    ll indexInGroup = k - (groupsBefore * (groupsBefore + 1)) / 2;
    b1 = n - 2 - groupsBefore, b2 = n - indexInGroup;
    string ans(n, 'a');
    ans[b1] = ans[b2] = 'b';
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
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}