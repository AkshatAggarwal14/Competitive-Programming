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

// just use SegTree:
// initialise with 1 if '0' or '1' and 2 if '?'
// calculate by adding on '?' and taking left or right on '0' or '1'
// Use Map for mapping of indexes of string to indexes in SegTree, and InvMap for the inverse mapping

void test() {
    ll n;
    string s;
    cin >> n >> s;
    n = (1LL << n);
    vector<ll> Map(n, 0), InvMap(n, 0);
    iota(1 + all(Map), 1);
    // also reverse on each level
    ll len = n / 2, x = 1;
    while (len > 1) {
        reverse(Map.begin() + x, Map.begin() + x + len);
        x += len;
        len /= 2;
    }
    reverse(all(Map));
    Map.pop_back();
    Map.insert(Map.begin(), 0);
    s = "." + s;

    for (ll i = 0; i < n; ++i) InvMap[Map[i]] = i;

    vector<ll> SegTree(n, -1);
    auto calc = [&](ll i) {
        if (i >= n / 2) {
            SegTree[i] = ((s[Map[i]] == '?') ? 2 : 1);
        } else {
            if (s[Map[i]] == '?') {
                SegTree[i] = SegTree[2 * i + 1] + SegTree[2 * i];
            } else if (s[Map[i]] == '0') {
                SegTree[i] = (SegTree[2 * i]);
            } else {
                SegTree[i] = (SegTree[2 * i + 1]);
            }
        }
    };

    auto update = [&](ll id, char ch) {
        ll i = InvMap[id];
        s[id] = ch;
        for (ll j = i; j >= 1; j /= 2) calc(j);
    };

    for (ll i = n - 1; i >= 1; --i) calc(i);

    ll q;
    cin >> q;
    while (q--) {
        ll id;
        char ch;
        cin >> id >> ch;
        update(id, ch);
        cout << SegTree[1] << '\n';
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
