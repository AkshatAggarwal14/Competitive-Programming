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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k), p(n);
    iota(all(p), 1);
    for (ll &A : a) cin >> A;
    rotate(p.begin(), p.begin() + 1, p.begin() + a[0]);
    for (ll i = 1; i < k; ++i) {
        rotate(p.begin() + a[i - 1], p.begin() + a[i - 1] + 1, p.begin() + a[i]);
    }
    for (ll &P : p) cout << P << ' ';
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