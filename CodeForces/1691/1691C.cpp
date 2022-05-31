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

//! Atmost 2 swaps, one to bring 1 at end, then to bring 1 at start
// end before start as at end it contributes to 01, and at start it contributes to 10

void test() {
    string s;
    ll n, k;
    cin >> n >> k >> s;
    auto solve = [&]() {
        ll sum = 0;
        for (ll i = 0; i < n - 1; ++i) sum += stoll(s.substr(i, 2));
        return sum;
    };
    ll c = count(all(s), '0');
    if (c == 0 || c == n) return void(cout << solve() << '\n');
    ll rSum = 0, rId = -1;
    for (ll i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            rId = i;
            break;
        }
        ++rSum;
    }
    if (rSum <= k) {
        swap(s[n - 1], s[rId]);
        k -= rSum;
    }
    ll lSum = 0, lId = -1;
    for (ll i = 0; i < n - 1; ++i) {  // to not use last 1
        if (s[i] == '1') {
            lId = i;
            break;
        }
        ++lSum;
    }
    if (lSum <= k && lId != -1) {
        swap(s[0], s[lId]);
        k -= lSum;
    }
    dbg(s);
    cout << solve() << '\n';
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
