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

vector<ll> next_greater(vector<ll> &a) {
    ll n = ll(a.size());
    vector<ll> res(n, n);
    stack<ll> stk;
    for (ll i = n - 1; i >= 0; --i) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        if (!stk.empty()) res[i] = stk.top();
        stk.push(i);
    }
    return res;
}

vector<ll> prev_greater(vector<ll> &a) {
    ll n = ll(a.size());
    vector<ll> res(n, -1);
    stack<ll> stk;
    for (ll i = 0; i < n; ++i) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        if (!stk.empty()) res[i] = stk.top();
        stk.push(i);
    }
    return res;
}

/*
    let i be index of maximum element in [j, k]
    S(j, k) > a[i]
    S(j, i - 1) + S(i, i) + S(i + 1, k) > a[i]
    S(j, i - 1) + S(i + 1, k) > 0
    Maximum(S(j, i - 1)) + Maximum(S(i + 1, k)) > 0

    Find j, k using prev_greater[i] + 1, next_greater[i] - 1
    Now to find Maximum(S(j, i - 1)) we need Maximum(S(j, n)) - suff[i]
    Now to find Maximum(S(i + 1, k)) we need Maximum(S(0, k)) - pref[i]
*/

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<ll> pref(n + 1), prev_g(prev_greater(a)), next_g(next_greater(a)), suff(n + 1);
    for (ll i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    for (ll i = n - 1; i >= 0; --i) suff[i] = suff[i + 1] + a[i];
    Sparse_Table<ll> Pmax(pref, [](const ll &i, const ll &j) { return max(i, j); });
    Sparse_Table<ll> Smax(suff, [](const ll &i, const ll &j) { return max(i, j); });
    for (ll i = 0; i < n; ++i) {
        ll leftID = prev_g[i] + 1, rightID = next_g[i] - 1;
        // check if max in left + max in right > 0
        ll maxLeft = Smax.query(leftID, i) - suff[i],
           maxRight = Pmax.query(i + 1, rightID + 1) - pref[i + 1];
        if (maxLeft + maxRight > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
