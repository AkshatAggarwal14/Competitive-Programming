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
    string w;
    ll p;
    cin >> w >> p;
    ll n = sz(w);
    priority_queue<pair<int, int>> a;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        a.push({int(w[i] - 'a' + 1), i});
        sum += int(w[i] - 'a' + 1);
    }
    set<int> rem;
    while (!a.empty() && sum > p) {
        auto T = a.top();
        a.pop();
        sum -= T.first;
        rem.insert(T.second);
    }
    string ans;
    for (int i = 0; i < n; ++i)
        if (!rem.count(i)) ans += w[i];
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
