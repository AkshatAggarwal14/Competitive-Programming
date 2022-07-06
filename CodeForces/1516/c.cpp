#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, g = 0;
    for (ll &i : a) cin >> i, sum += i, g = gcd(g, i);
    if (sum & 1) return void(cout << "0\n");  // if odd cant divide into 2 parts
    // else remove one element and check

    vector<bool> dp(sum / 2 + 1);
    // dp[i] = true if we can make a subset with sum = i
    // if can never achieve half sum
    dp[0] = true;
    for (ll i = 0; i < n; ++i)
        for (ll j = sum / 2; j >= a[i]; --j)
            if (dp[j - a[i]])
                dp[j] = true;
    if (!dp[sum / 2]) return void(cout << "0\n");

    // now divide array by its gcd, and we will surely have an odd element now, thus find it and output index
    // we could also divide array by 2, and repeat above process
    for (ll i = 0; i < n; ++i) {
        if ((a[i] / g) & 1) {
            cout << "1\n";
            cout << i + 1 << '\n';
            return;
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
