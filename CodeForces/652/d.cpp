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

void test() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    map<int, int> mp;
    for (int i = 0; auto &[x, y, id] : a) cin >> x >> y, id = i++, ++mp[x], ++mp[y];
    int compress = 0;
    for (auto &[x, y] : mp) y = compress++;
    for (auto &[x, y, i] : a) x = mp[x], y = mp[y];
    // sort by R, then add L in fenw and count marked in range
    vector<int> ans(n, -1);
    BIT<int> bit(compress + 5);
    sort(all(a), [](const auto &i, const auto &j) { return i[1] < j[1]; });  // sort by R ascending
    for (auto &[x, y, i] : a) {
        ans[i] = bit.get(x, y);
        bit.add(x, 1);
    }
    for (auto &x : ans) cout << x << '\n';
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
