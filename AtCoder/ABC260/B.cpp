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
    ll n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &A : a) cin >> A;
    for (auto &B : b) cin >> B;
    vector<ll> ans;
    vector<ll> pos(n);
    iota(all(pos), 0LL);
    sort(all(pos), [&](const ll &i, const ll &j) {
        if (a[i] == a[j]) return i > j;
        return a[i] < a[j];
    });
    while (x > 0 && !pos.empty()) {
        ans.push_back(pos.back());
        pos.pop_back();
        --x;
    }
    sort(all(pos), [&](const ll &i, const ll &j) {
        if (b[i] == b[j]) return i > j;
        return b[i] < b[j];
    });
    while (y > 0 && !pos.empty()) {
        ans.push_back(pos.back());
        pos.pop_back();
        --y;
    }
    sort(all(pos), [&](const ll &i, const ll &j) {
        if (a[i] + b[i] == a[j] + b[j]) return i > j;
        return a[i] + b[i] < a[j] + b[j];
    });
    while (z > 0 && !pos.empty()) {
        ans.push_back(pos.back());
        pos.pop_back();
        --z;
    }
    sort(all(ans));
    for (auto &A : ans) cout << A + 1 << '\n';
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
