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
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    // 1474C
    // Has to include last in step 1, try to simulate with every element with last one.
    ll n;
    cin >> n;
    vector<ll> a(2 * n);
    for (ll &A : a) cin >> A;
    sort(all(a));
    map<ll, ll> mp;
    vector<pair<ll, ll>> ans;
    for (ll k = 0; k < 2 * n - 1; ++k) {
        mp.clear();
        ans.clear();
        for (ll i = 0; i < 2 * n; ++i) ++mp[a[i]];
        ll e1 = a[k];
        ll e2 = a.back();
        --mp[e1];
        --mp[e2];
        if (mp[e1] == 0) mp.erase(e1);
        if (mp[e2] == 0) mp.erase(e2);
        ans.push_back({e2, e1});
        bool flag = true;
        while (!mp.empty()) {
            ll last = (*mp.rbegin()).first;
            if (!mp[e2 - last]) {
                flag = false;
                break;
            }
            ans.push_back({e2 - last, last});
            --mp[e2 - last];
            --mp[last];
            if (mp[last] == 0) mp.erase(last);
            if (mp[e2 - last] == 0) mp.erase(e2 - last);
            e2 = last;
        }
        if (flag) {
            cout << "YES\n";
            cout << ans[0].first + ans[0].second << '\n';
            for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << "NO\n";
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
