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
    string s;
    int rep;
    cin >> s >> rep;
    int mins = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
    set<int> vis;
    int cnt = 0;
    while (true) {
        int curr_hr = (mins / 60) % 24;
        int curr_mins = mins % 60;
        mins = curr_hr * 60 + curr_mins;
        if (vis.count(mins)) break;
        if (curr_hr / 10 == curr_mins % 10 && curr_hr % 10 == curr_mins / 10)
            ++cnt;
        vis.insert(mins);
        mins += rep;
        mins %= 3600;
    }
    cout << cnt << '\n';
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
