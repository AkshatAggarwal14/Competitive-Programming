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
    // number of distict values decrease drastically
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cntZero = 0;
    for (int step = 1; step < n; ++step) {
        sort(a.begin(), a.end());
        vector<ll> b;
        if (cntZero > 0) {
            cntZero--;
            b.push_back(a[0]);
        }
        for (int i = 1; i < sz(a); ++i) {
            if (a[i] == a[i - 1]) {
                cntZero++;
            } else {
                b.push_back(a[i] - a[i - 1]);
            }
        }
        a = b;
    }
    if (cntZero) {
        cout << "0\n";
    } else {
        cout << a[0] << "\n";
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
