#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

class MergeSortTree {
   public:
    MergeSortTree(vector<int>& arr) {
        n = int(arr.size());
        tree.resize(4 * n);
        sum.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    ll query(int l, int r, ll x) {
        return query(0, 0, n - 1, l, r, x);
    }

   private:
    vector<vector<int>> tree;
    vector<vector<ll>> sum;  // Corrected: tree should store vectors of integers
    int n;

    void build(int node, int start, int end, vector<int>& a) {
        if (start == end) {
            tree[node].push_back(a[start]);
            sum[node].push_back(a[start]);
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, a);
            build(2 * node + 2, mid + 1, end, a);
            merge(node);
        }
    }

    void merge(int node) {
        int i = 0, j = 0;
        vector<int>& left = tree[2 * node + 1];
        vector<int>& right = tree[2 * node + 2];
        vector<int>& merged = tree[node];
        vector<ll>& ms = sum[node];
        while (i < ll(left.size()) && j < ll(right.size())) {
            if (left[i] < right[j]) {
                merged.push_back(left[i++]);
            } else {
                merged.push_back(right[j++]);
            }
        }

        while (i < ll(left.size())) {
            merged.push_back(left[i++]);
        }

        while (j < ll(right.size())) {
            merged.push_back(right[j++]);
        }

        ms.push_back(merged[0]);
        for (ll k = 1; k < ll(merged.size()); ++k) {
            ms.push_back(ms.back() + merged[k]);
        }
    }

    ll query(int node, int start, int end, int l, int r, ll x) {
        if (start > r || end < l) {
            return 0LL;
        }
        if (start >= l && end <= r) {
            // Count elements less than or equal to x in the sorted array
            int index = int(upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin()) - 1;
            if (index == -1) return 0LL;
            return sum[node][index];
        }

        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r, x) + query(2 * node + 2, mid + 1, end, l, r, x);
    }
};

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    MergeSortTree mst(a);
    int q;
    cin >> q;

    ll lastAns = 0;
    for (int i = 0; i < q; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        x ^= lastAns;
        y ^= lastAns;
        z ^= lastAns;
        lastAns = mst.query(int(x - 1), int(y - 1), z);
        cout << lastAns << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
