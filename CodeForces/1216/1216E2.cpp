#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll q;
    cin >> q;
    auto len_full_groups = [&](ll K) -> pair<ll, ll> {
        // [1 * (1 + log10(10)), 2 * (1 + log10(9)), 3 * (1 + log10(8)), 4 * (1 + log10(7)),...]
        auto _sum = [&](ll s) { return (s * (s + 1)) / 2; };
        auto sum = [&](ll l, ll r) {
            if (l > r) swap(l, r);
            ll S = _sum(r) - _sum(l - 1);
            return S;
        };
        auto can = [&](ll x) -> ll {
            ll nth = sz(to_string(x)) - 1;
            ll digits = 0;
            ll term = 9;
            ll start = x;
            // digits += num of digits * occurences for each num of digits
            for (ll i = 1; i <= nth; ++i) {
                digits += (sum(start - term + 1, start)) * i;
                start -= (term);
                term *= 10;
            }
            return digits + (nth + 1) * sum(1, start);
        };
        ll L = 0, R = 1;
        while (can(R) < INF) R *= 2;
        --L, ++R;
        ll ans = 0, len = 0;
        while (R > L + 1) {
            ll mid = (L + R) / 2;
            ll val = can(mid);
            if (val < K) {
                L = mid;
                ans = mid;
                len = val;
            } else {
                R = mid;
            }
        }
        return {ans, len};
    };
    auto solve = [&](ll K) {
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

        ll L = 1, R = ll(1e18), ans = -1, can_ans = -1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            ll calc = can(M);
            if (calc >= K) {
                R = M;
                ans = M;
                can_ans = can(M);
            } else {
                L = M;
            }
        }
        ll left = can_ans - K;
        string res = to_string(ans);
        return res[sz(res) - 1 - left];
    };
    while (q--) {
        ll k;
        cin >> k;
        auto full_groups = len_full_groups(k);  // calculate using binary search too
        // https://codeforces.com/contest/1177/problem/A <- leftover problem
        ll left = k - full_groups.second;
        cout << solve(left) << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
