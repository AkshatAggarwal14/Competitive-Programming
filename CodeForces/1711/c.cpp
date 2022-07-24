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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    for (auto &A : a) cin >> A;
    sort(all(a));
    reverse(all(a));
    bool flag = false;
    // use 2 colours of each type then repeat them if you can
    // rotate grid and repeat

    // check row-wise and col-wise
    auto check = [&]() {
        ll left = m;
        vector<ll> can_use;
        for (ll i; i < k; ++i) {
            ll rows = a[i] / n;
            if (rows >= 2 && left >= 2) {
                left -= 2;
                if (a[i] - n * 2 > 0) can_use.push_back(a[i] - n * 2);
            } else {
                break;
            }
        }
        sort(all(can_use));
        // now use colours again if you can
        while (!can_use.empty() && left != 0) {
            ll rows = can_use.back() / n;
            left -= min(left, rows);
            can_use.pop_back();
        }
        if (left == 0) flag = true;
    };

    check();
    swap(n, m);
    check();
    cout << (flag ? "Yes\n" : "No\n");
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
