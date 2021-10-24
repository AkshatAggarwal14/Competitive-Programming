#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
const ll inf = INT_MAX;

void Solution() {
    ll R, C;
    cin >> R >> C;
    vector<vector<pair<ll, ll>>> g(R * C);
    vector<ll> d(R * C, inf);
    ll src = 0, dest = R * C - 1;
    vector<vector<ll>> A(R, vector<ll>(C - 1));
    vector<vector<ll>> B(R - 1, vector<ll>(C));
    auto get = [&](ll x, ll y) {
        return x * C + y;
    };
    for (ll i = 0; i < R; ++i) {
        for (ll j = 0; j < C - 1; ++j) {
            cin >> A[i][j];
            g[get(i, j)].push_back({get(i, j + 1), A[i][j]});
            g[get(i, j + 1)].push_back({get(i, j), A[i][j]});
        }
    }
    for (ll i = 0; i < R - 1; ++i) {
        for (ll j = 0; j < C; ++j) {
            cin >> B[i][j];
            g[get(i, j)].push_back({get(i + 1, j), B[i][j]});
        }
    }
    for (ll i = 0; i < R; ++i) {
        for (ll j = 0; j < C; ++j) {
            for (ll k = 1; k <= i; ++k) {
                g[get(i, j)].push_back({get(i - k, j), 1 + k});
            }
        }
    }
    d[src] = 0;
    set<pair<ll, ll>> s;  //{distance, node}
    s.insert({0, src});
    while (!s.empty()) {
        ll dis = s.begin()->first;
        ll vertex = s.begin()->second;
        s.erase(s.begin());
        for (pair<ll, ll> &x : g[vertex]) {
            ll newDis = dis + x.second;
            ll newVer = x.first;
            if (newDis < d[newVer]) {
                s.erase({d[newVer], newVer});  // erase old distance
                d[newVer] = newDis;            // update
                s.insert({d[newVer], newVer});
            }
        }
    }
    cout << d[dest] << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}