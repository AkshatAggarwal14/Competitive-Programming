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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;

    auto can = [&](ll K) -> bool {
        ll days = 0;
        vector<ll> b(a);
        for (ll i = 0; i < n - 1; ++i) {
            ll can_deliver = min(b[i], K);
            ll left = b[i] - can_deliver;
            b[i + 1] += left;
            ++days;
        }
        days += (b[n - 1] + K - 1) / K;
        return days <= m;
    };

    ll l = 1, r = ll(1e9);
    --l, ++r;
    ll min_K = *max_element(all(a));
    while (r > l + 1) {
        ll M = (l + r) / 2;
        if (can(M)) {
            r = M;
            min_K = M;
        } else {
            l = M;
        }
    }

    cout << min_K << '\n';
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