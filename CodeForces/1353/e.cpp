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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int total_ones = int(count(all(s), '1'));
    int ans = n;
    for (int i = 0; i < k; ++i) {
        vector<int> t;
        for (int j = i; j < n; j += k) {
            if (s[j] == '1') {
                t.push_back(1);
            } else {
                t.push_back(-1);
            }
        }
        // Kadane's algorithm for each string
        int max_ending_here = 0;
        int max_so_far = 0;
        int _start = 0;
        int start = 0;
        int end = -1;
        for (int j = 0; j < sz(t); j++) {
            max_ending_here = max_ending_here + t[j];
            if (max_ending_here < 0) {
                max_ending_here = 0;
                _start = j + 1;
            }
            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
                start = _start;
                end = j;
            }
        }
        int zeroes_in_between = 0, other_ones = 0, ones = 0;
        for (int j = 0; j < sz(t); ++j) {
            if (t[j] == 1) ++ones;
            if (j < start || j > end) {
                if (t[j] == 1) ++other_ones;
            } else {
                if (t[j] == -1) ++zeroes_in_between;
            }
        }
        ans = min(ans, zeroes_in_between + other_ones + (total_ones - ones));
    }
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
