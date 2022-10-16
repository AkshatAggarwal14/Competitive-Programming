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
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> st;
    for (auto &x : a) cin >> x, st.insert(x);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) b[i] = {a[i], a[i]};
    sort(b.rbegin(), b.rend());
    int pref = 0;
    for (int i = 0; i < min(n, 32); ++i) {
        pref |= b[0].first;
        if (st.contains(b[0].second)) {
            cout << b[0].second << ' ';
            st.erase(st.find(b[0].second));
        } else {
            break;
        }
        b[0].first = 0;
        for (auto &x : b) {
            x.first |= pref;
            x.first ^= pref;
        }
        sort(b.rbegin(), b.rend());
    }
    while (!st.empty()) {
        cout << *st.begin() << ' ';
        st.erase(st.begin());
    }
    cout << '\n';
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
