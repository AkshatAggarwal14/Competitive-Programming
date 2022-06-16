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
    ll k;
    cin >> k;

    auto can = [&](ll x) -> ll {
        ll nth = sz(to_string(x)) - 1;
        ll last = stoll("1" + string(nth, '0')) - 1;
        ll digits = 0;
        // now find 9 + 90 + 900.. sz(to_string(x)) - 1 terms
        ll term = 9;
        for (ll i = 1; i <= nth; ++i) {
            digits += (term * i);
            term *= 10;
        }
        return digits + (x - last) * (nth + 1);
    };

    ll L = 1, R = ll(1e12), ans = -1, can_ans = -1;
    --L, ++R;
    while (R > L + 1) {
        ll M = (L + R) / 2;
        ll calc = can(M);
        if (calc >= k) {
            R = M;
            ans = M;
            can_ans = can(M);
        } else {
            L = M;
        }
    }
    ll left = can_ans - k;
    string res = to_string(ans);
    cout << res[sz(res) - 1 - left] << '\n';
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