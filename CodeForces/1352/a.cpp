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
    // number of round numbers required will be number of digits in n that are no zero, example: 509 = 500 + 9, 1012 = 1000 + 10 + 2
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    // count number of digits that are not zero
    for (int i = 0; i < n; ++i)
        if (s[i] - '0') cnt++;
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i)
        if (s[i] - '0') cout << s[i] - '0' << string(n - 1 - i, '0') << ' ';
    cout << '\n';
}

/*
    ! M2 Brute force method by making a vector with all round numbers until n
    vl vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    sort(all(vec), greater<ll>());
    vl ans;
    ll n, k = 0;
    cin >> n;
    for (ll i = 0; i < vec.size() && n > 0; i++)
    {
        ll times = n / vec[i];
        n -= vec[i] * times;
        k += times;
        if (times != 0)
            ans.insert(ans.end(), times, vec[i]);
    }
    cout << k << "\n";
    tr(it, ans) cout << *it << " ";
*/

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