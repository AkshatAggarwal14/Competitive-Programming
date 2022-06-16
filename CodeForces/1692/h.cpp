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
    vector<int> a(n);
    map<int, vector<int>> mp;
    int ans = -1, mx = 0, l = -1, r = -1;
    for (int i = 0; i < n; ++i) cin >> a[i], mp[a[i]].push_back(i);
    for (auto &[x, y] : mp) {
        // {value, index}
        // value of consecutive is 1s and gaps is -(size of gap) to find most dense area
        vector<array<int, 2>> t;
        for (int i = 0; i < sz(y); ++i) {
            t.push_back({1, y[i]});
            if (i + 1 < sz(y)) {
                t.push_back({-(y[i + 1] - y[i] - 1), -1});
            }
        }
        // Kadane's algorithm for each x
        int max_ending_here = 0;
        int max_so_far = 0;
        int _start = 0;
        int start = 0;
        int end = -1;
        for (int i = 0; i < sz(t); i++) {
            max_ending_here = max_ending_here + t[i][0];
            if (max_ending_here < 0) {
                max_ending_here = 0;
                _start = i + 1;
            }
            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
                start = _start;
                end = i;
            }
        }
        if (max_so_far > mx) {
            ans = x;
            mx = max_so_far;
            l = t[start][1], r = t[end][1];
        }
    }
    cout << ans << ' ' << l + 1 << ' ' << r + 1 << '\n';
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
