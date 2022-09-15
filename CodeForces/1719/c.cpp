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
    int n, q;
    cin >> n >> q;
    deque<int> a(n);
    for (auto &A : a) cin >> A;
    auto b = a;
    vector<int> win(n);
    for (int i = 0; i < n; ++i) {
        int p1 = a.front();
        a.pop_front();
        int p2 = a.front();
        a.pop_front();
        win[i] = max(p1, p2);
        a.push_front(win[i]);
        a.push_back(min(p1, p2));
    }
    // we have results of first n rounds, after these only "n" wins
    while (q--) {
        int i, k;
        cin >> i >> k, --i;
        int lb = int(distance(win.begin(), lower_bound(win.begin(), win.end(), b[i])));
        int ub = int(distance(win.begin(), upper_bound(win.begin(), win.end(), b[i]))) - 1;
        if (lb <= ub) {
            ub = min(ub, k - 1);
            int wins = ub - lb + 1;
            if (k > n && b[i] == n) {
                wins += k - n;
            }
            cout << max(wins, 0) << '\n';
        } else {
            cout << "0\n";
        }
    }
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
