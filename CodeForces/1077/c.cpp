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
    vector<ll> a(n), cnt(N, 0);
    for (ll &A : a) cin >> A, ++cnt[A];
    ll sum = accumulate(all(a), 0LL);
    set<ll> to_erase;
    for (ll i = 0; i < n; ++i) {
        ll val = sum - 2 * a[i];
        if (val >= 0 && val < N && cnt[val]) {
            if (val == a[i] && cnt[val] == 1) continue;
            to_erase.insert(val);
            cnt[val] = 0;
        }
    }
    vector<ll> res;
    for (ll i = 0; i < n; ++i)
        if (to_erase.contains(a[i])) res.push_back(i + 1);
    cout << sz(res) << '\n';
    for (auto &i : res) cout << i << ' ';
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
