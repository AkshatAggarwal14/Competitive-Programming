// Dynamic Range Sum Queries

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
    for (int i = 0; i < int(a.size()); ++i) {
        tree[n + i] = a[i];
    }
    for (int i = n - 1; i >= 1; --i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    auto query = [&](const auto &self, int node, int node_lo, int node_hi, int q_lo, int q_hi) -> int {
        if (q_lo <= node_lo && node_hi <= q_hi)
            return tree[node];
        if (node_hi < q_lo || q_hi < node_lo)
            return 0;
        int last_in_left = (node_lo + node_hi) / 2;
        return self(self, 2 * node, node_lo, last_in_left, q_lo, q_hi) +
               self(self, 2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi);
    };

    // TODO: iterative update
    // auto update = [&](int index, int value) {
    //     tree[n + index] = value;
    //     for (int j = (n + index) / 2; j >= 1; j /= 2) {
    //         tree[j] = tree[2 * j] + tree[2 * j + 1];
    //     }
    // };

    // TODO: recursive update
    // here q_lo and q_hi are same
    auto update_R = [&](const auto &self, int node, int node_lo, int node_hi, int q_lo, int q_hi, int value) -> void {
        if (q_lo <= node_lo && node_hi <= q_hi) {
            // happens only once when leaf [id, id]
            tree[node] = value;
            return;
        }
        // in disjoint just return
        if (node_hi < q_lo || q_hi < node_lo) return;
        int last_in_left = (node_lo + node_hi) / 2;
        self(self, 2 * node, node_lo, last_in_left, q_lo, q_hi, value);
        self(self, 2 * node + 1, last_in_left + 1, node_hi, q_lo, q_hi, value);

        // after updating now set, Post Call Area
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    };

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int id, val;
            cin >> id >> val, --id;
            // update(id, val);
            update_R(update_R, 1, 0, n - 1, id, id, val);
        } else {
            int lo, hi;
            cin >> lo >> hi, --lo, --hi;
            cout << query(query, 1, 0, n - 1, lo, hi) << '\n';
        }
    }
    return 0;
}