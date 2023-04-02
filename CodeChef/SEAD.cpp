#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
class Sparse_Table {
    ll N, K;
    vector<ll> LOG;
    vector<vector<T>> st;

    ll log2_floor(unsigned long long i) { return 63 - __builtin_clzll(i); }

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr)
        : N(ll(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)) {
        LOG[1] = 0;
        for (ll i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (ll i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = T::merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(ll L, ll R) {
        if (L > R) swap(L, R);
        ll j = LOG[R - L + 1];
        T res = T::merge(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

struct Node {
    ll val;
    Node() : Node(0) {}
    Node(ll v) : val(v) {}
    static Node merge(const Node &i, const Node &j) { return Node(max(i.val, j.val)); }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<Node> D(n - 1);
    for (int i = 0; i < n - 1; ++i) D[i].val = a[i + 1] - a[i];
    Sparse_Table<Node> st(D);
    int q;
    cin >> q;
    while (q--) {
        int t, d;
        cin >> t >> d;
        int k = int(distance(a.begin(), upper_bound(a.begin(), a.end(), t))) - 1;
        int L = -1, R = k;
        while (R > L + 1) {
            int M = (L + R) / 2;
            if (st.query(M, k - 1).val <= d) {
                R = M;
            } else {
                L = M;
            }
        }
        cout << R + 1 << '\n';
    }
    return 0;
}
