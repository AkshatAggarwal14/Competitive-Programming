// https://www.spoj.com/problems/GIVEAWAY/ - Sqrt Decomposition, make arrays for each block
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// fix for compiler optimization
const int block_size = 710;  // sqrt(N)

struct Square_Root_Decomposition {
    int n, block_size;
    vector<ll> a;
    vector<vector<ll>> block;
    Square_Root_Decomposition(vector<ll> &v) : a(v) {
        n = int(a.size());
        for (int i = 0; i < n; ++i) {
            if (block.empty() || int(block.back().size()) == block_size) block.emplace_back();
            block.back().push_back(a[i]);
        }
        for (auto &bl : block) sort(bl.begin(), bl.end());
    }
    // O(block_size)
    void update(int idx, ll val) {
        // update block
        vector<ll> &bl = block[idx / block_size];
        int sz = int(bl.size()),
            pos = int(lower_bound(bl.begin(), bl.end(), a[idx]) - bl.begin());
        bl[pos] = val;
        while (pos + 1 < sz && bl[pos] > bl[pos + 1])
            swap(bl[pos], bl[pos + 1]), ++pos;
        while (pos >= 1 && bl[pos] < bl[pos - 1])
            swap(bl[pos], bl[pos - 1]), --pos;
        // update array
        a[idx] = val;
    }
    // O(block_size)
    int query(int l, int r, ll val) {
        int ans = 0, lb = l / block_size, rb = r / block_size;
        if (lb == rb) {
            for (int i = l; i <= r; ++i) {
                ans += (a[i] >= val);
            }
        } else {
            for (int i = l; i < (lb + 1) * block_size; ++i) {
                ans += (a[i] >= val);
            }
            for (int i = rb * block_size; i <= r; ++i) {
                ans += (a[i] >= val);
            }
            for (int i = lb + 1; i < rb; ++i) {
                ans += block_size - int(upper_bound(block[i].begin(), block[i].end(), val) - block[i].begin());
            }
        }
        return ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    Square_Root_Decomposition sqd(a);
    cin >> m;
    while (m--) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r;
            ll v;
            cin >> l >> r >> v, --l, --r;
            cout << sqd.query(l, r, v) << '\n';
        } else {
            int id;
            ll v;
            cin >> id >> v, --id;
            sqd.update(id, v);
        }
    }
}