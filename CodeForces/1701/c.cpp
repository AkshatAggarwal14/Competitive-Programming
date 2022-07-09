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
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> cnt(n + 1, 0);
    ll mx = 0;
    for (ll &i : a) cin >> i, ++cnt[i], mx = max(mx, cnt[i]);
    auto can = [&](ll hours) {
        ll tasks_left = 0, tasks_can_do = 0;
        for (ll i = 1; i <= n; ++i) {
            ll hours_left = max(hours - cnt[i], 0LL);
            tasks_left += cnt[i] - min(hours, cnt[i]);
            tasks_can_do += hours_left / 2;
        }
        return tasks_left <= tasks_can_do;
    };
    ll L = 1, R = mx;
    --L, ++R;
    while (R > L + 1) {
        ll M = (R + L) / 2;
        (can(M) ? R : L) = M;
    }
    cout << R << '\n';
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
