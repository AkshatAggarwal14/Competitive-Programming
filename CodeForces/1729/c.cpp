#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s;
    cin >> s;
    vector<pair<char, ll>> v;
    ll i = 1;
    for (auto &x : s) {
        v.push_back({x, i++});
    }
    sort(all(v));
    vector<ll> ans;
    if (s.front() <= s.back()) {
        for (auto &[x, y] : v) {
            if (x >= s.front() && x <= s.back()) ans.push_back(y);
        }
    } else {
        sort(all(v), [&](const pair<char, ll> &A, const pair<char, ll> &B) {
            if (A.first == B.first) return A.second < B.second;
            return A.first > B.first;
        });
        for (auto &[x, y] : v) {
            if (x <= s.front() && x >= s.back()) ans.push_back(y);
        }
    }
    dbg(v, ans);
    assert(ans[0] == 1 && ans.back() == int(s.size()));
    dbg(v);
    ll val = 0;
    for (ll j = 1; j < sz(ans); ++j) val += abs(int(s[ans[j - 1] - 1] - 'a') - int(s[ans[j] - 1] - 'a'));
    cout << val << ' ' << sz(ans) << '\n';
    for (auto &x : ans) cout << x << ' ';
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
