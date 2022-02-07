// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> in(n);
    set<ll> st1, st2;
    for (ll i = 1; i <= n; ++i) st1.insert(i);
    for (auto &x : in) cin >> x, st1.erase(x);  // st1, st2 contains elements not in input
    st2 = st1;
    vector<ll> res1(n, -1), res2;
    res1[0] = in[0];
    for (ll i = 1; i < n; ++i)
        if (in[i] != in[i - 1]) res1[i] = in[i];  // marking the known elements(where in[] changes)
    res2 = res1;
    // for res1, each unknown is just first element from set after which its removed
    for (auto &x : res1) {
        if (x != -1) continue;
        x = *st1.begin();
        st1.erase(x);
    }
    // for res2, each unknown is, the numbers in st2, just smaller than in[i]
    for (int i = -1; auto &x : res2) {
        ++i;
        if (x != -1) continue;
        auto it = st2.lower_bound(in[i]);
        if (it != st2.begin()) --it;
        x = *it;
        st2.erase(x);
    }
    for (auto &x : res1) cout << x << ' ';
    cout << '\n';
    for (auto &x : res2) cout << x << ' ';
    cout << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}