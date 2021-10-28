#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

ll *segTree;

ll getGCDOfNumber(ll startNode, ll endNode, ll startQuery, ll endQuery, ll si) {
    if (startNode > endQuery || endNode < startQuery)
        return 0;
    if (startQuery <= startNode && endQuery >= endNode)
        return segTree[si];
    ll mid = startNode + (endNode - startNode) / 2;
    return gcd(getGCDOfNumber(startNode, mid, startQuery, endQuery, si * 2 + 1),
               getGCDOfNumber(mid + 1, endNode, startQuery, endQuery, si * 2 + 2));
}

ll ff(ll startNode, ll endNode, ll arr[], ll n) {
    if (startNode > endNode) swap(startNode, endNode);
    return getGCDOfNumber(0, n - 1, startNode, endNode, 0);
}

ll buildSegementTree(ll arr[], ll startNode, ll endNode, ll si) {
    if (startNode == endNode) {
        segTree[si] = arr[startNode];
        return segTree[si];
    }
    ll mid = startNode + (endNode - startNode) / 2;
    segTree[si] = gcd(buildSegementTree(arr, startNode, mid, si * 2 + 1),
                      buildSegementTree(arr, mid + 1, endNode, si * 2 + 2));
    return segTree[si];
}

ll *constructendNodegmentTree(ll arr[], ll n) {
    ll height = (ll)(ceil(log2(n)));
    ll size = 2 * static_cast<ll>(pow(2LL, height)) - 1;
    segTree = new ll[size];
    buildSegementTree(arr, 0, n - 1, 0);
    return segTree;
}

ll a[2000];

//https://www.tutorialcup.com/interview/tree/gcds-of-given-index-ranges-in-an-array.htm
//! Partial - segtree
void Solution() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    constructendNodegmentTree(a, n);
    ll mx = -1;
    for (ll i = 0; i < n - 1; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            ll g = a[i] * a[j];
            if (i > 0) g = gcd(g, ff(0, i - 1, a, n));
            if (j < n - 1) g = gcd(g, ff(j + 1, n - 1, a, n));
            if (j != i + 1) g = gcd(g, ff(i + 1, j - 1, a, n));
            mx = max(mx, g);
        }
    }
    cout << mx << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}