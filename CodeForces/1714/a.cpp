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

// find first time greater than given, if doesnt exist use first
void test() {
    ll n, h, m;
    cin >> n >> h >> m;
    ll init = h * 60 + m;
    vector<ll> mins(n);
    for (auto &M : mins) {
        ll hh, mm;
        cin >> hh >> mm;
        M = hh * 60 + mm;
    }
    sort(all(mins));
    auto it = lower_bound(all(mins), init);
    ll val = 0;
    if (it == mins.end()) {
        val = 24 * 60 + mins[0];
    } else {
        val = *it;
    }
    ll diff = val - init;
    ll ansh = (diff / 60) % 24;
    ll ansm = diff % 60;
    cout << ansh << ' ' << ansm << '\n';
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
