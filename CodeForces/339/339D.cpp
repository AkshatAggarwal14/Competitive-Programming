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
    ll n, m;
    cin >> n >> m;
    n = (1LL << n);
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    vector<pair<ll, ll>> SegTree(2 * n, {-1, -1});  // power of 2
    for (ll i = 0; i < n; ++i) SegTree[n + i] = {a[i], 1};
    for (ll i = n - 1; i >= 0; --i) {
        auto lChild = SegTree[2 * i];
        auto rChild = SegTree[2 * i + 1];
        if (lChild.second == 1) {
            SegTree[i] = {lChild.first | rChild.first, 0};
        } else {
            SegTree[i] = {lChild.first ^ rChild.first, 1};
        }
    }

    auto update = [&](ll i, ll v) {
        SegTree[n + i].first = v;
        for (ll j = (n + i) / 2; j >= 1; j /= 2) {
            auto lChild = SegTree[2 * j];
            auto rChild = SegTree[2 * j + 1];
            if (lChild.second == 1) {
                SegTree[j] = {lChild.first | rChild.first, 0};
            } else {
                SegTree[j] = {lChild.first ^ rChild.first, 1};
            }
        }
    };

    while (m--) {
        ll p, b;
        cin >> p >> b, --p;
        // a[p] = b
        update(p, b);
        cout << SegTree[1].first << '\n';
    }
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
