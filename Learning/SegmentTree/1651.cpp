// Range Update Queries

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    while (__builtin_popcount(uint32_t(n)) != 1) ++n;

    vector<int> tree(2 * n);
    // build the tree
    for (int i = 0; i < int(a.size()); ++i) tree[n + i] = a[i];

    //! as i dont want to compute sums of the complete ranges, i just want to update them when i want
    // for (int i = n - 1; i >= 1; --i)
    //     tree[i] = tree[2 * i] + tree[2 * i + 1];

    auto query = [&](const auto &self, int node, int node_lo, int node_hi, int q_lo, int q_hi) -> int {
        if (q_lo <= node_lo && node_hi <= q_hi)
            return tree[node];
        if (node_hi < q_lo || q_hi < node_lo)
            return 0;
        int last_in_left = (node_lo + node_hi) / 2;
        int res = self(self, 2 * node, node_lo, last_in_left, q_lo, q_hi) +
                  self(self, 2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi);
        return res + tree[node];  //! tree[node] as i ask my parents and add my own value
    };

    auto update_R = [&](const auto &self, int node, int node_lo, int node_hi, int q_lo, int q_hi, int value) -> void {
        if (q_lo <= node_lo && node_hi <= q_hi) {
            tree[node] += value;
            return;
        }
        // in disjoint just return
        if (node_hi < q_lo || q_hi < node_lo) return;
        int last_in_left = (node_lo + node_hi) / 2;
        self(self, 2 * node, node_lo, last_in_left, q_lo, q_hi, value);
        self(self, 2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi, value);
    };

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a_, b, u;
            cin >> a_ >> b >> u, --a_, --b;
            update_R(update_R, 1, 0, n - 1, a_, b, u);
        } else {
            int k;
            cin >> k, --k;
            cout << query(query, 1, 0, n - 1, k, k) << '\n';
        }
    }
    return 0;
}