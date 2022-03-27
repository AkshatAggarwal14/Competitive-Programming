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
    auto count_digits_smaller = [](ll n) {
        --n;
        ll digs = 0;
        for (ll i = n; i > 0; i /= 10) ++digs;
        ll low = static_cast<ll>(pow(10, digs - 1));
        ll count = 0;
        while (low > 0) {
            count += digs * (n - low + 1);
            n = low - 1;
            low /= 10;
            --digs;
        }
        return count;
    };

    ll q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        ll L = 0, R = 1, digs_less = -1;
        while (count_digits_smaller(R) < k) R *= 2;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            ll c = count_digits_smaller(M);
            if (c <= k) {
                digs_less = c;
                L = M;
            } else {
                R = M;
            }
        }
        ll digs_left = k - digs_less;
        dbg(digs_left, L);
        if (digs_left == 0) {
            cout << to_string(L - 1).back() << '\n';
        } else {
            cout << to_string(L)[digs_left - 1] << '\n';
        }
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
