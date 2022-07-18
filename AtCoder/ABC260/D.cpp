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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) cin >> p[i], --p[i];
    vector<ll> ans(n, -1);
    set<ll> last;  // contains last elements
    vector<ll> which(n, -1);
    vector<vector<ll>> segs(n);
    ll mark = 0;
    for (ll i = 0; i < n; ++i) {
        dbg(last, which, segs, ans, p[i]);
        auto it = last.lower_bound(p[i]);
        if (it == last.end()) {
            which[p[i]] = mark++;
            segs[which[p[i]]].push_back(p[i]);
            last.insert(p[i]);

            if (sz(segs[which[p[i]]]) == k) {
                last.erase(p[i]);
                for (auto &e : segs[which[p[i]]]) {
                    ans[e] = i + 1;
                }
                segs[which[p[i]]].clear();
            }
        } else {
            ll e = *it;
            which[p[i]] = which[e];
            last.erase(e);
            segs[which[p[i]]].push_back(p[i]);
            last.insert(p[i]);

            if (sz(segs[which[p[i]]]) == k) {
                last.erase(p[i]);
                for (auto &e_ : segs[which[p[i]]]) {
                    ans[e_] = i + 1;
                }
                segs[which[p[i]]].clear();
            }
        }
    }
    for (auto &A : ans) cout << A << '\n';
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
