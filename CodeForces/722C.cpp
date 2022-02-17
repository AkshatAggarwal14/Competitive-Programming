#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

struct DSU {
    int N;
    vector<int> par, siz;
    vector<ll> sum;  //!
    DSU(int n) : N(n), par(N), siz(N, 1), sum(N, 0) {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] != X) par[X] = root(par[X]);
        return par[X];
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void join(int X, int Y) {
        X = root(X), Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        sum[Y] += sum[X];
        sum[X] = 0;
    }
    int get_size(int X) { return siz[root(X)]; }
    int components() {
        int cnt = 0;
        for (int i = 0; i < N; ++i) cnt += (root(i) == i);
        return cnt;
    }
};

void Solution() {
    //! DSU
    /*
    instead of removing elements go in reverse order and add elements, join using DSU, and find max answer along the process.
    */
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int &A : a) cin >> A;
    for (int &P : p) cin >> P, --P;
    reverse(all(p));
    DSU dsu(n);
    ll ans = 0;
    set<int> in;
    vector<ll> out;
    for (int i = 0; i < n; ++i) {
        out.push_back(ans);
        if (in.count(p[i] - 1)) dsu.join(p[i], p[i] - 1);
        if (in.count(p[i] + 1)) dsu.join(p[i], p[i] + 1);
        dsu.sum[dsu.root(p[i])] += a[p[i]];
        ans = max(ans, dsu.sum[dsu.root(p[i])]);
        in.insert(p[i]);
    }
    reverse(all(out));
    for (ll &x : out) cout << x << '\n';

    //! Set
    /*
    int n;
    cin >> n;
    vector<int> arr(n + 1), p(n + 1);
    vector<ll> pre(n + 1);
    multiset<ll> s;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
    set<int> dead;
    dead.insert(0);
    dead.insert(n + 1);
    s.insert(pre[n]);
    for (int i = 1; i <= n; i++) {
        int x = p[i];
        auto it = dead.upper_bound(x);
        int ub = *it;
        --it;
        int lb = *it;
        s.erase(s.find(pre[ub - 1] - pre[lb]));
        s.insert(pre[ub - 1] - pre[x]);
        s.insert(pre[x - 1] - pre[lb]);
        dead.insert(x);
        cout << (*s.rbegin()) << '\n';
    }
    */
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}