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

int32_t main() {
    // number of pairs {i, j} such that A[i] > A[j] and i < j
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    BIT<int> bit(n + 1);  // 1 <= a[i] <= n, if not can compress a[] according to relative ordering
    int inv = 0;
    for (int i = 0; i < n; ++i) {
        inv += bit.get(a[i] + 1, n);
        bit.add(a[i], 1);
    }
    cout << inv << '\n';
}
