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
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll ops = 0;
    while (n != 1) {
        vector<ll> temp;
        for (ll i = 0; i < n; i += 2) {
            ll A = (a[i] + 1) / 2;
            ll B = (a[i + 1] + 1) / 2;
            if (A != B) return void(cout << "-1\n");
            if (a[i] > a[i + 1]) ++ops;
            temp.push_back(A);
        }
        n /= 2;
        a.swap(temp);
    }
    cout << ops << '\n';
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
