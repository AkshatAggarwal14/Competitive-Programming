#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll cnt = count(all(a), 0);
    // when we have a 0, we can arrange all neighbours before it
    if (cnt) return void(cout << n - cnt << '\n');
    ll mn = *min_element(all(a));
    ll cnt_mn = count(all(a), mn);
    // 2 2 3 4 5 <- 2*n + elements>2 as larger elements can be counted twice
    cout << n * mn + (n - cnt_mn) << '\n';
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