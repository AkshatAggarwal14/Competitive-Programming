#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

template <class T>
class BIT {
   public:
    vector<T> tree;
    int n;

    BIT(int _n) : n(_n + 1) { tree.resize(n); }
    BIT(const vector<T> &a) : BIT(int(a.size()) + 1) {
        for (int i = 0; i < int(a.size()); ++i) add(i, a[i]);
    }

    void add(int i, T delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += (i & -i);
        }
    }

    T get(int i) {
        ++i;
        T sum{};
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
    T get(int l, int r) { return get(r) - get(l - 1); }
};

void test() {
    int q;
    cin >> q;
    int n = 1;
    vector<array<ll, 3>> queries(q);
    for (auto &[type, vi, xi] : queries) {
        cin >> type >> vi;
        if (type == 2) {
            cin >> xi;
        } else {
            xi = -1;
            ++n;
        }
    }

    ll pos = 2;
    vector<vector<ll>> g(n + 1);
    for (auto &[type, vi, xi] : queries) {
        if (type == 1) {
            g[vi].push_back(pos);
            g[pos].push_back(vi);
            ++pos;
        }
    }

    vector<ll> euler;
    vector<int> in(n + 1), out(n + 1);
    int timer = 0;
    auto dfs = [&](const auto &self, ll node, ll par) -> void {
        euler.push_back(node);
        in[node] = timer++;
        for (auto &child : g[node]) {
            if (child != par) {
                self(self, child, node);
            }
        }
        euler.push_back(node);
        out[node] = timer++;
    };

    dfs(dfs, 1, -1);

    int length = int(euler.size());
    BIT<ll> bit(length + 10);

    int node = 2;
    for (auto &[type, vi, xi] : queries) {
        if (type == 1) {
            ll parAns = bit.get(in[vi]);
            bit.add(in[node], -parAns);
            bit.add(out[node] + 1, parAns);
            ++node;
        } else {
            bit.add(in[vi], xi);
            bit.add(out[vi] + 1, -xi);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << bit.get(in[i]) << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
