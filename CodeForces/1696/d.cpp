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

struct graph {
    ll n;
    vector<vector<ll>> adj;
    vector<ll> d;
    graph(ll &vertices) : n(vertices), adj(n), d(n, -1) {}
    void add_edge(ll u, ll v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void bfs(ll source) {
        queue<ll> q;
        q.push(source), d[source] = 0;
        while (!q.empty()) {
            ll parent = q.front();
            q.pop();
            for (ll &child : adj[parent]) {
                if (d[child] != -1) continue;
                d[child] = d[parent] + 1;
                q.push(child);
            }
        }
    }
};

template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    ll N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(ll(arr.size())), K(__lg(N)), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP) {
        LOG[1] = 0;
        for (ll i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (ll i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(ll L, ll R) {
        if (L > R) swap(L, R);
        ll j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};

void test() {
    using pl = pair<ll, ll>;
    ll n;
    cin >> n;
    vector<pl> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    // gives minimum idx
    Sparse_Table<pl> Min(a, [&](const pl &i, const pl &j) {
        return ((i.first < j.first) ? i : j);
    });
    // gives maximum idx
    Sparse_Table<pl> Max(a, [&](const pl &i, const pl &j) {
        return ((i.first > j.first) ? i : j);
    });
    // {mx, mn}
    auto edge_type_1 = [&](ll i) {
        ll L = i, R = n - 1;
        --L, ++R;
        // find farthest L such that in [i, L] a[i] is maximum
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (i == Max.query(i, M).second) {
                L = M;
            } else {
                R = M;
            }
        }
        // find index with minimum element in [i, L] and reduce it to [i, found] -> [mx, mn]
        return Min.query(i, L).second;
    };
    // {mn, mx}
    auto edge_type_2 = [&](ll i) {
        ll L = i, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (i == Min.query(i, M).second) {
                L = M;
            } else {
                R = M;
            }
        }
        return Max.query(i, L).second;
    };
    graph g(n);
    for (ll i = 0; i < n; ++i) {
        ll e1 = edge_type_1(i);
        ll e2 = edge_type_2(i);
        if (e1 != i) g.add_edge(i, e1);
        if (e2 != i) g.add_edge(i, e2);
    }
    g.bfs(0);
    cout << g.d[n - 1] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
