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

const ll INF = 1e12 + 5;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll H, n, sum = 0;
    cin >> H >> n;
    vector<ll> h(n);
    for (ll &hh : h) cin >> hh;
    for (ll i = 0; i < n; ++i) {
        sum += h[i];
        if (H + sum <= 0) return void(cout << i + 1 << '\n');
    }

    if (sum >= 0) return void(cout << "-1\n");
    auto can = [&](ll times) -> pair<bool, ll> {
        ll temp = H + (times - 1) * sum;
        for (ll i = 0; i < n; ++i) {
            temp += h[i];
            if (temp <= 0) return {true, i + 1};
        }
        return {false, -1};
    };
    ll L = 1, R = 1;
    while (!can(R).first) R *= 2;

    --L, ++R;
    ll ans_index = -INF;
    while (R > L + 1) {
        ll M = (R + L) / 2;
        auto C = can(M);
        if (C.first) {
            ans_index = C.second + (M - 1) * n;
            R = M;
        } else {
            L = M;
        }
    }
    cout << ans_index << '\n';
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