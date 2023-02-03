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
        // assert(i >= 1 && i <= n);
        T sum{};
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
    T get(int l, int r) { return get(r + 1) - get(l); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    BIT<int> b(n + 5);
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r, --l, --r;
            b.add(l, 1);
            b.add(r + 1, -1);
        } else {
            int i;
            cin >> i, --i;
            int times = b.get(i);
            int element = a[i];
            while (times > 0 && element > 9) {
                int sm = 0, t = element;
                while (t) {
                    sm += t % 10;
                    t /= 10;
                }
                element = sm;
                --times;
            }
            cout << element << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}