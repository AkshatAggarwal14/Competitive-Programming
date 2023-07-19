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
    ll n, m, h;
    cin >> n >> m >> h;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<array<ll, 3>> details(n);
    for (ll index = 0; auto &x : a) {
        for (auto &y : x) cin >> y;
        sort(x.begin(), x.end());
        ll j = 0, penalty = 0, curr = 0, cnt = 0;
        for (; j < m; ++j) {
            curr += x[j];
            if (curr > h) {
                break;
            }
            penalty += curr;
            ++cnt;
        }
        details.push_back({cnt, penalty, index});
        ++index;
    }
    sort(details.begin(), details.end(), [&](const array<ll, 3> &A, const array<ll, 3> &B) {
        if (A[0] != B[0]) return A[0] > B[0];
        if (A[1] != B[1]) return A[1] < B[1];
        return A[2] < B[2];
    });
    for (ll i = 0; i < n; ++i) {
        if (details[i][2] == 0) return void(cout << i + 1 << '\n');
    }
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
