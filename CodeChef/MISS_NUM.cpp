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

const ll L = 1;
const ll R = 1e4;
void test() {
    vector<ll> a(4);
    for (ll &A : a) cin >> A;
    sort(all(a));
    do {
        ll a_plus_b = a[0];
        ll a_minus_b = a[1];
        // a + b = A, a - b = B, 2a = A + B
        if ((a_plus_b + a_minus_b) & 1) continue;
        ll A = (a_plus_b + a_minus_b) / 2;
        ll B = a_plus_b - A;
        if (A >= L && A <= R && B >= L && B <= R) {
            ll C = A * B;
            ll D = ll(floor(double(A) / double(B)));
            if ((C == a[2] && D == a[3]) || (C == a[3] && D == a[2]))
                return void(cout << A << ' ' << B << '\n');
        }
    } while (next_permutation(all(a)));
    cout << "-1 -1\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
