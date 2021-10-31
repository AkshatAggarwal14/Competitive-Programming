#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define yes return void(cout << "YES\n")
#define no return void(cout << "NO\n")

void Solution() {
    ll n, num;
    cin >> n;
    set<ll> st;
    for (ll i = 0; i < (1LL << n); ++i) cin >> num, st.insert(num);
    if (sz(st) == 1 || ((sz(st) == 2) && (*st.begin() + 1 == *st.rbegin()))) yes;
    no;
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}