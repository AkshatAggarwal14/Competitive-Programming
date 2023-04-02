// https://vjudge.net/problem/UVA-12003 - Sqrt Decomposition, make arrays for each block
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// fix for compiler optimization
const int block_size = 550;  // sqrt(N)

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
                ans += (a[i] < val);
            }
        } else {
            for (int i = l; i < (lb + 1) * block_size; ++i) {
                ans += (a[i] < val);
            }
            for (int i = rb * block_size; i <= r; ++i) {
                ans += (a[i] < val);
            }
            for (int i = lb + 1; i < rb; ++i) {
                ans += int(lower_bound(block[i].begin(), block[i].end(), val) - block[i].begin());
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
    ll u;
    cin >> n >> m >> u;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    Square_Root_Decomposition sqd(a);
    while (m--) {
        int l, r, p;
        ll v;
        cin >> l >> r >> v >> p, --l, --r, --p;
        int k = sqd.query(l, r, v);
        ll new_value = (u * 1LL * k) / (r - l + 1);
        sqd.update(p, new_value);
    }
    for (auto &x : sqd.a) {
        cout << x << '\n';
    }
}