#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

void test() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n, -1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> v;
    set<int> st;
    for (int i = 1; i <= n; ++i) st.insert(i);
    for (int i = 0; i < n; ++i)
        if (a[i] == b[i])
            c[i] = a[i], st.erase(a[i]);
        else
            v.push_back(i);
    // equal values at right position, store position and remaining elements for unequal positions
    vector<int> ans1 = c, ans2 = c;
    if (v.size() == 1) {
        // if only one directly set
        ans1[v[0]] = *st.begin();
        for (auto &x : ans1) cout << x << ' ';
        return;
    }
    // otherwise two cases can be recovered
    ans1[v[0]] = *st.begin(), ans1[v[1]] = *st.rbegin();
    ans2[v[1]] = *st.begin(), ans2[v[0]] = *st.rbegin();
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (ans1[i] != a[i]) ++cnt1;
        if (ans1[i] != b[i]) ++cnt2;
    }
    if (cnt1 == 1 && cnt2 == 1) {
        for (auto &x : ans1) cout << x << ' ';
    } else {
        for (auto &x : ans2) cout << x << ' ';
    }
    cout << '\n';
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
