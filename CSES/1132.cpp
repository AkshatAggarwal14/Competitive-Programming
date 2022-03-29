// diameter
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

void test() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    auto bfs = [&](ll source) {
        vector<ll> d(n, -1);
        queue<ll> q;
        q.push(source);
        d[source] = 0;
        while (!q.empty()) {
            ll par = q.front();
            q.pop();
            for (auto &child : g[par]) {
                if (d[child] != -1) continue;
                d[child] = d[par] + 1;
                q.push(child);
            }
        }
        return d;
    };
    vector<ll> d1(bfs(0));
    ll far1 = max_element(all(d1)) - d1.begin();
    vector<ll> end_1(bfs(far1));
    ll far2 = max_element(all(end_1)) - end_1.begin();
    vector<ll> end_2(bfs(far2));
    for (ll i = 0; i < n; ++i) {
        cout << max(end_1[i], end_2[i]) << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
