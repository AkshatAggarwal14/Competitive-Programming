#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<ll> more(n);
    vector<array<ll, 2>> can(n);
    ll can_inc = 0, low = 0;
    for (ll i = 0; i < n; ++i) {
        more[i] = b[i] - a[i];
        // can_inc += max(0LL, more[i]);
        can_inc += max(0LL, more[i]);
        low += min(0LL, more[i]);
        can[i] = {more[i], a[i]};
    }
    sort(all(can), [](const array<ll, 2> &A, const array<ll, 2> &B) {
        if (A[1] == B[1]) return A[0] < B[0];
        return A[1] < B[1];
    });
    dbg(can);
    ll ans = abs(low), pos = can_inc;
    for (ll k = 0; k < n; ++k) {
        dbg(can_inc, ans);
        if (abs(can_inc) >= pos) {
            cout << 2 * ans << ' ';
        } else {
            cout << "-1 ";
        }
        can_inc -= max(0LL, can[k][0]);
        // can_inc -= max(0LL, can[k][0]);
        ans += can[k][1];
    }
    cout << '\n';
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
