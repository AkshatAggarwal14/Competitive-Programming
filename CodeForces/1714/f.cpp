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

// as tree 1 is connected to x, 2 is connected to x, 3 is connected to x
// OR 1 2 or 3 is x
void test() {
    ll n, aa, bb, cc;
    cin >> n >> aa >> bb >> cc;
    ll sum = aa + bb + cc;
    if (sum % 2) return void(cout << "NO\n");
    sum /= 2;
    if (aa > sum || bb > sum || cc > sum) return void(cout << "NO\n");
    ll a = sum - bb, b = sum - cc, c = sum - aa;
    ll cnt = (a == 0) + (b == 0) + (c == 0);
    if (cnt > 1) return void(cout << "NO\n");
    vector<array<ll, 2>> edges;
    if (a == 0) {
        ll val = 4, prev = 1;
        for (ll i = 0; i < b - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 2});

        prev = 1;
        for (ll i = 0; i < c - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 3});

        while (sz(edges) < n - 1) {
            edges.push_back({1, val});
            ++val;
        }
    } else if (b == 0) {
        ll val = 4, prev = 2;
        for (ll i = 0; i < a - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 1});

        prev = 2;
        for (ll i = 0; i < c - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 3});

        while (sz(edges) < n - 1) {
            edges.push_back({1, val});
            ++val;
        }
    } else if (c == 0) {
        ll val = 4, prev = 3;
        for (ll i = 0; i < b - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 2});

        prev = 3;
        for (ll i = 0; i < a - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 1});

        while (sz(edges) < n - 1) {
            edges.push_back({1, val});
            ++val;
        }
    } else {
        ll val = 5, prev = 4;
        for (ll i = 0; i < a - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 1});

        prev = 4;
        for (ll i = 0; i < b - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 2});

        prev = 4;
        for (ll i = 0; i < c - 1; ++i) {
            edges.push_back({prev, val});
            prev = val;
            ++val;
        }
        edges.push_back({prev, 3});

        while (sz(edges) < n - 1) {
            edges.push_back({4, val});
            ++val;
        }
    }
    if (sz(edges) != n - 1) return void(cout << "NO\n");
    for (auto &[u, v] : edges) {
        if (u > n || v > n) return void(cout << "NO\n");
    }
    cout << "YES\n";
    for (auto &[u, v] : edges) cout << u << ' ' << v << '\n';
}

int32_t
main() {
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
