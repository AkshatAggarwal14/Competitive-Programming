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
    ll x[3], y[3];
    for (ll i = 0; i < 3; ++i) cin >> x[i] >> y[i];
    ll ans = 0;
    if (y[0] == y[1] && y[2] < y[0]) {
        ans = abs(x[0] - x[1]);
    } else if (y[0] == y[2] && y[1] < y[0]) {
        ans = abs(x[0] - x[2]);
    } else if (y[1] == y[2] && y[0] < y[1]) {
        ans = abs(x[1] - x[2]);
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