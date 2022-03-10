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
    ll n;
    cin >> n;
    vector<ll> even, odd;
    for (ll i = 1, num; i <= n; ++i) {
        cin >> num;
        if (num < 0) num = -num;
        if (i & 1)
            odd.push_back(num);
        else
            even.push_back(num);
    }
    ll val = accumulate(all(odd), 0LL) - accumulate(all(even), 0LL);
    ll mini_odd = *min_element(all(odd));
    ll maxi_even = *max_element(all(even));
    val = max(val, val + 2 * (maxi_even - mini_odd));
    cout << val << '\n';
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