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
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (!(a & 1)) a >>= 1;
        st.insert(a);
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        while (!(b[i] & 1)) b[i] >>= 1;
    }
    // after dividing by 2, we need to match prefixes
    dbg(st, b);
    sort(b.begin(), b.end());  // odds from small to big
    for (int i = 0; i < n; ++i) {
        while (b[i]) {
            auto it = st.lower_bound(b[i]);
            if (it != st.end() && (*it == b[i])) {
                st.erase(it);
                break;
            }
            b[i] >>= 1;  // make smaller
        }
        if (b[i] == 0) return void(cout << "NO\n");
    }
    cout << "YES\n";
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
