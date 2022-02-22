#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<ll> mx(n + 1, -INF);
    for (ll i = 0; i < n; i++) {
        ll sum = 0;
        for (ll j = i; j < n; j++) {
            sum += a[j];
            mx[j - i + 1] = max(mx[j - i + 1], sum);
        }
    }
    // mx[i] contains maximum sum of subarray of length i
    for (ll k = 0; k <= n; k++) {
        ll ans = 0;
        // for each subarray + x * min(k, subarray_len)
        for (ll i = 1; i <= n; i++)
            ans = max(ans, mx[i] + (min(k, i) * x));
        cout << ans << ' ';
    }
    cout << '\n';
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