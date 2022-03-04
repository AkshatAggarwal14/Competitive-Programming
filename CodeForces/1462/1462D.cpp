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

// https://www.codechef.com/problems/REMADJ
void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    ll sum = accumulate(all(a), 0LL);
    // sum of array remains constant
    // calculate minimum number of operations required to make all elements of array equal if in one operation we can replace two adjacent elements with there sum
    // so, each element must be sum/x for some divisor x.
    // the original array A can be partitioned into subarrays [1…P1],[P1+1,…P2],…,[Py−2+1,…,Py−1],[Py−1+1,N]
    ll ans = n - 1;
    for (ll i = 1; i <= n; i++) {
        if (abs(sum) % i == 0) {
            ll ele = i, val = sum / i;
            ll s = 0;
            for (ll &x : a) {
                s += x;
                if (s == val) s = 0, ele--;
            }
            if (ele <= 0) amin(ans, n - i);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}