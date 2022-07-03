#include <bits/stdc++.h>
using namespace std;

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