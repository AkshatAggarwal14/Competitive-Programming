#include <bits/stdc++.h>
using namespace std;
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
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    BIT<ll> bit(n + 5);
    while (m--) {
        char type;
        cin >> type;
        if (type == '1') {
            int l, r;
            ll v;
            cin >> l >> r >> v, --r;
            bit.add(l, v);
            bit.add(r + 1, -v);
        } else {
            int i;
            cin >> i;
            cout << bit.get(i) << '\n';
        }
    }
}