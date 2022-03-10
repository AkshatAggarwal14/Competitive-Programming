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
    vector<ll> a(n), b(n);
    for (ll &A : a) cin >> A;
    for (ll &B : b) cin >> B;
    ll a1 = INF, a2 = INF;
    ll b1 = INF, b2 = INF;
    for (ll i = 0; i < n; i++) {
        a1 = min(a1, abs(a[0] - b[i]));
        a2 = min(a2, abs(a[n - 1] - b[i]));
        b1 = min(b1, abs(b[0] - a[i]));
        b2 = min(b2, abs(b[n - 1] - a[i]));
    }
    cout << min({
        abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]),  // | |
        a1 + b1 + a2 + b2,                            // X X
        a2 + b2 + abs(a[0] - b[0]),                   // | X
        a1 + b1 + abs(a[n - 1] - b[n - 1]),           // X |
        abs(a[0] - b[n - 1]) + abs(b[0] - a[n - 1]),  // X
        abs(a[0] - b[n - 1]) + a2 + b1,               //!
        abs(b[0] - a[n - 1]) + a1 + b2,
    });
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