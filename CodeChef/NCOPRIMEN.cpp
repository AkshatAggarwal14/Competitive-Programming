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

vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n + 5);
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    // a  b  c d  e  f g
    // a 2a 2d d 2d 2g g
    a[n + 1] = 2;
    for (ll i = 1; i <= n; i++) {
        if ((i % 3) == 1) continue;
        if ((i % 3) == 2)
            a[i] = a[i - 1] * 2;
        else
            a[i] = a[i + 1] * 2;
    }
    for (ll i = 1; i <= n; i++) cout << a[i] << ' ';
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