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

ll calc(vector<ll> &arr) {
    // calculate for x and y seperately as just need to be added
    // (3x1 + 2x2 + x3) - (3x4 + 2x3 + x2)..
    ll n = sz(arr);
    sort(arr.rbegin(), arr.rend());
    ll res = 0;
    ll mul = n - 1;
    for (ll i = 0; i < n; ++i) {
        res += mul * arr[i];
        mul -= 2;
    }
    return res;
}

// https://www.geeksforgeeks.org/sum-manhattan-distances-pairs-points/
void Solution() {
    map<ll, vector<ll>> mpx, mpy;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> col(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> col[i][j];
            mpx[col[i][j]].push_back(i);
            mpy[col[i][j]].push_back(j);
        }
    }
    ll ans = 0;
    for (auto &[u, v] : mpx) ans += calc(mpx[u]) + calc(mpy[u]);
    cout << ans << '\n';
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