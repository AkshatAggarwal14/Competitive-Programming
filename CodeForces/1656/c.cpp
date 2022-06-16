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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll c0 = 0, c1 = 0;
    for (ll &A : a) cin >> A, c0 += (A == 0), c1 += (A == 1);
    if (c1 && c0)
        cout << "NO\n";
    else if (c1) {
        sort(all(a));
        bool flag = false;
        for (ll i = 1; i < n; i++) {
            if (a[i] - 1 == a[i - 1]) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    } else
        cout << "YES\n";
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
