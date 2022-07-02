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
    int n;
    cin >> n;
    deque<ll> a(n);
    map<ll, ll> cnt;
    for (ll &i : a) cin >> i, ++cnt[i];
    bool isPerm = true;
    for (ll i = 1; i <= n; ++i) isPerm &= (cnt[i]);

    // minimum elems should be at ends and minimum of remaining array must be min + 1
    // k = 0 is always permutation as it is [1]
    string ans;
    ll curr = 1;
    for (auto &[small, occ] : cnt) {
        if (occ == 0) continue;  // &= cnt[i]
        if (curr != small || sz(ans) == n - 1) break;
        ans += '1';
        if (a.front() == small) {
            a.pop_front();
        } else if (a.back() == small) {
            a.pop_back();
        } else {
            break;
        }
        if (occ > 1) break;
        curr++;
    }
    while (sz(ans) < n - 1) ans += '0';
    ans += (isPerm ? '1' : '0');
    reverse(all(ans));
    cout << ans << '\n';
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
