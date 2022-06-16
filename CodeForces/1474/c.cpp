#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int;
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
    vector<array<ll, 2>> pairs;

    auto remove = [&](ll element) {
        --mp[element];
        if (mp[element] == 0) mp.erase(element);
    };

    for (ll k = 0; k < 2 * n - 1; ++k) {
        mp.clear(), pairs.clear();
        for (ll i = 0; i < 2 * n; ++i) ++mp[a[i]];
        ll e1 = a[k];
        ll e2 = a.back();
        remove(e1), remove(e2);
        pairs.push_back({e2, e1});
        bool flag = true;
        while (!mp.empty()) {
            ll last = (*mp.rbegin()).first;
            if (!mp[e2 - last]) {
                flag = false;
                break;
            }
            pairs.push_back({e2 - last, last});
            remove(last), remove(e2 - last);
            e2 = last;
        }
        if (flag) {
            cout << "YES\n";
            cout << pairs[0][0] + pairs[0][1] << '\n';
            for (auto &[x, y] : pairs) cout << x << ' ' << y << '\n';
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
