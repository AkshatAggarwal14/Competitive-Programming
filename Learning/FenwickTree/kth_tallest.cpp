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

    // finds first index where get(i) >= k
    int find_first(T k) {  // O(log(n)) - Walking the BIT
        int i = 0;
        int mask = (1 << __lg(n - 1));
        while (mask != 0) {
            int t_i = i + mask;  // the midpoint of the current interval
            mask >>= 1;          // halve the current interval
            if (t_i >= n)        // avoid overflow
                continue;
            if (k > tree[t_i]) {
                // if smaller, subtract tree[t_i] and move up
                i = t_i;         // update index
                k -= tree[t_i];  // update the frequency for the next iteration
            }
        }
        return i;
    };
};

const int N = 17;

int32_t main() {
    // given heights and count of people with that height [1, 1e6]
    // you can update the count of people with a given height
    // or you can query the height of kth tallest person, k [1, 1e18]

    BIT<ll> bit(N + 1);
    int n;
    cin >> n;
    vector<pair<int, int>> h(n);
    for (auto &[_h, _c] : h) cin >> _h >> _c, bit.add(_h, _c);
    // update -> usual
    // TODO: M1 - to query use binary search
    auto query = [&](ll k) {
        // Complexity = O(log(n) * log(n))
        // BS * BIT.query()
        int l = 1, r = N;
        --l, ++r;
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (bit.get(m) >= k)
                r = m;
            else
                l = m;
        }
        return r;
    };
    // TODO: M2 - walk the BIT using BIT.find_first_greater()
    ll q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        cout << query(k) << '\n';
        // cout << bit.find_first(k) << '\n';
    }
}

/*
h: 1, 2, 3, 4, 5, 6
c: 8, 2, 10, 100, 1, 2

test:
6
1 8
2 2
3 10
4 100
5 1
6 2
5
1
2
3
10
21
*/