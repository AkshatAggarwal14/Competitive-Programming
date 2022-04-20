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

vector<pair<ll, ll>> factorise_pair(const ll &n) {
    vector<pair<ll, ll>> C;
    ll temp = n, cnt = 0;
    for (ll i = 2; i * i <= n; ++i) {
        cnt = 0;
        while (temp % i == 0) {
            cnt++;
            temp /= i;
        }
        if (cnt) C.push_back({i, cnt});
    }
    if (temp > 1) C.push_back({temp, 1});
    return C;
}

void test() {
    ll X, c;
    cin >> X >> c;
    auto facs = factorise_pair(X);
    ll P = 1;
    for (auto &[x, y] : facs) {
        y %= c;
        y = min(y, c - y);
        for (ll i = 0; i < y; ++i) P *= x;
    }
    cout << P << '\n';
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
