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
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n), cnt(c + 1), pref(c + 2, 0);
    for (ll &A : a) cin >> A, ++cnt[A];
    pref[0] = cnt[0];
    for (ll i = 1; i <= c; ++i) pref[i] += pref[i - 1] + cnt[i];
    for (ll x = 1; x <= c; ++x) {
        if (!cnt[x]) continue;
        // z is y/x
        for (ll z = 1; z * x <= c; ++z) {
            ll L = x * z;
            ll R = min(x * (z + 1) - 1, c);
            if (pref[R] - pref[L - 1] > 0 && cnt[z] == 0)
                return void(cout << "No\n");
        }
    }
    cout << "Yes\n";
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