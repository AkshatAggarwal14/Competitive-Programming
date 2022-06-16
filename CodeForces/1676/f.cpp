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
    vector<ll> a(n);
    priority_queue<ll, vector<ll>, greater<ll>> mark;
    map<ll, ll> mp;
    for (ll &A : a) cin >> A, ++mp[A];
    for (auto &[x, y] : mp)
        if (y >= k) mark.push(x);
    if (mark.empty()) return void(cout << "-1\n");
    ll last = mark.top() - 1;
    ll cnt = 0, res = 0;
    ll l = mark.top(), r = l;
    ll ans_L = l, ans_R = r;
    while (!mark.empty()) {
        if (last == -1 || mark.top() == last + 1) {
            ++cnt;
            r = mark.top();
        } else {
            cnt = 1;
            l = mark.top();
            r = mark.top();
        }
        if (r - l >= ans_R - ans_L) {
            ans_R = r;
            ans_L = l;
        }
        res = max(res, cnt);
        last = mark.top();
        mark.pop();
    }
    cout << ans_L << ' ' << ans_R << '\n';
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
