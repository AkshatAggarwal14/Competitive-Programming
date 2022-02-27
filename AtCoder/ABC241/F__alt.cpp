#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

void Solution() {
    auto BS = [](const vector<ll> &a, const ll &value) -> pair<ll, ll> {
        ll L = 0, R = sz(a) - 1, ans_L = -1, ans_R = -1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (a[M] < value) {
                L = M, ans_L = a[L];
            } else {
                R = M, ans_R = a[R];
            }
        }
        return {ans_L, ans_R};
    };

    ll h, w, n, sx, sy, gx, gy;
    cin >> h >> w >> n >> sx >> sy >> gx >> gy;
    map<ll, vector<ll>> X, Y;
    for (ll i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        X[x].push_back(y), Y[y].push_back(x);
    }
    for (auto &[_, v] : X) sort(all(v));
    for (auto &[_, v] : Y) sort(all(v));
    map<pair<ll, ll>, ll> d;
    queue<pair<ll, ll>> bfs;
    bfs.emplace(sx, sy);
    d[{sx, sy}] = 0;
    auto add = [&](ll x, ll y, ll px, ll py) {
        if (d.count({x, y})) return;
        d[{x, y}] = d[{px, py}] + 1;
        bfs.emplace(x, y);
    };
    while (!bfs.empty()) {
        auto [x, y] = bfs.front();
        bfs.pop();
        if (X.count(x)) {
            auto [L, R] = BS(X[x], y);
            if (L != -1) add(x, L + 1, x, y);
            if (R != -1) add(x, R - 1, x, y);
        }
        if (Y.count(y)) {
            auto [L, R] = BS(Y[y], x);
            if (L != -1) add(L + 1, y, x, y);
            if (R != -1) add(R - 1, y, x, y);
        }
    }
    cout << (d.count({gx, gy}) ? d[{gx, gy}] : -1) << '\n';
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