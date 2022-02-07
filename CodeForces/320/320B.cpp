#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, x, y, type, src = -1, ext = -1;
    cin >> n;
    vector<array<ll, 2>> intervals;
    vector<ll> vis(n, false);  // n is max number of intervals
    auto dfs = [&](const auto &self, ll idx) -> bool {
        if (idx == ext) return true;
        vis[idx] = true;
        ll a = intervals[idx][0], b = intervals[idx][1];
        for (ll i = 0; i < sz(intervals); ++i) {
            ll c = intervals[i][0], d = intervals[i][1];
            if (!vis[i] && ((c < a && a < d) || (c < b && b < d)))
                if (self(self, i)) return true;
        }
        return false;
    };
    while (n--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            intervals.push_back({x, y});
        } else {
            cin >> src >> ext;
            --src, --ext;
            fill(vis.begin(), vis.begin() + sz(intervals), false);
            cout << (dfs(dfs, src) ? "YES\n" : "NO\n");
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}