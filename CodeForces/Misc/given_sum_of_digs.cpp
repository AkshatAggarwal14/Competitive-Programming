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
    ll n, sum;
    cin >> n >> sum;
    vector<string> ans;
    auto dfs = [&](const auto &self, string s, ll curr_sum) {
        if (stoll(s) > n) return;
        if (curr_sum > sum) return;
        if (curr_sum == sum) {
            ans.push_back(s);
            return;
        }
        for (char c = '0'; c <= '9'; ++c) {
            s.push_back(c);
            self(self, s, curr_sum + c - '0');
            s.pop_back();
        }
    };
    for (ll i = 1; i <= 9; ++i) {
        dfs(dfs, string(1, char(i + '0')), i);
    }
    for (auto &x : ans) cout << x << ' ';
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
