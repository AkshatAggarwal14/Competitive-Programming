#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto& container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 998244353;
const ll INF = 1e18;

ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
ll modpow(ll x, ll y, ll m = MOD) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}

/*
f(i) is
0 if i is 0
2 when i is even
1 when i is a binary palindrome (has to be odd)
3 if otherwise odd

Thus, ANS = 2*evens + (bin_pal) + (odds - bin_pal) * 3

Now total numbers = 2^n - 1
odds = 2^(n-1)
evens = odds - 1

Now to find bin_pal,
bin_pal[i] = binary palindromes with i bits
bin_pal[1] = 1
bin_pal[2] = 1
bin_pal[3] = 2
bin_pal[4] = 2...

find sum until N of sequence 1 + 1 + 2 + 2 ... for cnt of all bin_pal
*/

void Solution() {
    ll n;
    cin >> n;
    // 1 + 1 + 2 + 2 + ... for all bits until N
    auto cnt_bin_pal = [&]() -> ll {
        if (n & 1) {
            return (M(2 * (modpow(2, (n + 1) / 2) - 1)) - modpow(2, (n + 1) / 2 - 1));
        } else {
            return M(2 * (modpow(2, n / 2) - 1));
        }
    };
    ll bin_pal = cnt_bin_pal();
    ll odds = modpow(2, n - 1);
    ll left = M(odds - bin_pal);
    ll evens = M(odds - 1);
    ll ans = M(bin_pal * 1 + evens * 2 + left * 3);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE* in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE* out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}