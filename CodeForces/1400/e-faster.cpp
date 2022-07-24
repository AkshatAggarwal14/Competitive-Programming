#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct RMQ {
    int n, levels;
    vector<T> values;
    vector<vector<int>> range_low;

    int min_index(int a, int b) const { return values[b] < values[a] ? b : a; }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        build();
    }

    void build() {
        levels = 32 - __builtin_clz(n);
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = min_index(
                    range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    int rmq_index(int a, int b) const {
        assert(a < b);
        int level = 31 - __builtin_clz(b - a);
        return min_index(range_low[level][a],
                         range_low[level][b - (1 << level)]);
    }

    int rmq_value(int a, int b) const { return values[rmq_index(a, b)]; }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // https://mzhang2021.github.io/cp-blog/divide-and-conquer/#:~:text=But%20we%20can%20do%20better
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;

    RMQ<ll> Min;
    Min.build(a);

    // O(n) as each range in O(1)
    function<ll(int, int, ll)> dfs = [&](int l, int r, ll delta) {
        if (l > r) return 0LL;

        int idx = Min.rmq_index(l, r + 1);
        // we will apply type 1 operation (min a_i) times
        ll mn = a[idx] - delta;
        // return minimum of our two options: solve recursively, or just apply type 2 operations to each element
        return min(mn + dfs(l, idx - 1, delta + mn) +
                       dfs(idx + 1, r, delta + mn),
                   ll(r - l + 1));
    };
    cout << dfs(0, n - 1, 0LL) << '\n';
}