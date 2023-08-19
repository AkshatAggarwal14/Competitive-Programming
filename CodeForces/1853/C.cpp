#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    //! couldnt do
    ll n, k;
    cin >> n;
    ll ans = 0;
    vector<ll> X(N);
    iota(X.begin(), X.end(), 1);
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    for (ll _ = 0; _ < 10; ++_) {
        vector<ll> todel;
        for (auto &x : a) {
            todel.push_back(X[x - 1]);
            cout << X[x - 1] << ' ';
        }
        cout << '\t';
        for (auto &x : todel) {
            X.erase(find(X.begin(), X.end(), x));
        }
        cout << X[0];
        cout << '\n';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
