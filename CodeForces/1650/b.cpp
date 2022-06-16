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
    // so ans in last 2 segments of size 'a'
    ll l, r, a;
    cin >> l >> r >> a;
    ll mx_div = (r / a);
    ll left = r - a * mx_div;
    dbg(mx_div, left);
    ll ans = 0;
    if (a * (mx_div - 1) + a - 1 >= l) ans = mx_div - 1 + a - 1;
    ans = max(ans, mx_div + left);
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