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
    ll t;
    cin >> t;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<ll> b(n);
    for (ll &B : b) cin >> B;
    bool ok = true;
    for (ll i = 1; i < n; ++i)
        if (gcd(b[i], b[i - 1]) == 1) return void(cout << "GCD\n");
    ;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) cnt += (a[i] != b[i]);
    if (cnt > (2 * n) / 3) return void(cout << "MORE\n");
    cout << "OK\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}