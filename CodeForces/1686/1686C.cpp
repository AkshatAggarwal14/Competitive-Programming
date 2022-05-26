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
    for (auto &A : a) cin >> A;
    if (n & 1) return void(cout << "NO\n");
    sort(all(a));
    vector<ll> res(n);
    ll i1 = 0, i2 = n / 2;
    for (ll i = 0; i < n; ++i) {
        if (i % 2 == 0)
            res[i] = a[i1++];
        else
            res[i] = a[i2++];
    }
    bool flag = true;
    for (ll i = 0; i < n; ++i) {
        if (!((res[i] > res[(i + n - 1) % n] && res[i] > res[(i + n + 1) % n]) || (res[i] < res[(i + n - 1) % n] && res[i] < res[(i + n + 1) % n]))) {
            flag = false;
        }
    }
    if (flag) {
        cout << "YES\n";
        for (auto &A : res) cout << A << ' ';
        cout << '\n';
        return;
    }
    cout << "NO\n";
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
