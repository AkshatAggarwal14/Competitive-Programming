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
    int L, R;
    cin >> L >> R;
    auto print = [&](int a, int b, int c, int d) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    };
    if (!(L & 1)) {
        print(L, L + 1, L + 2, L + 3);
    } else {
        if (R - L == 3)
            cout << "-1\n";
        else
            print(L + 1, L + 2, L + 3, L + 4);
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
