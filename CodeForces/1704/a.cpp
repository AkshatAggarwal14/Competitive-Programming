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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    bool ok = true;
    for (int i = 0; i < m - 1; i++) {  // last m - 1 same
        if (b.back() != a.back()) {
            ok = false;
            break;
        }
        b.pop_back();
        a.pop_back();
    }
    if (!ok) {
        cout << "NO" << '\n';
        return;
    }
    if (b == "0" && a == string(n - m + 1, '1')) {
        cout << "NO" << '\n';
        return;
    }
    if (b == "1" && a == string(n - m + 1, '0')) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
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
