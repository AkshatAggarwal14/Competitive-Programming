#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    int n;
    cin >> n;
    map<int, int> opposite;
    for (int i = 0; i < n; ++i) {
        int left, right;
        cin >> left >> right;
        opposite[left] = right;
        opposite[right] = left;
    }

    stack<int> st;
    for (int i = 1; i <= 2 * n; ++i) {
        if (st.empty()) {
            st.push(i);
        } else {
            if (opposite[i] == st.top()) {
                st.pop();
            } else {
                st.push(i);
            }
        }
    }

    cout << (st.empty() ? "No" : "Yes");
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
