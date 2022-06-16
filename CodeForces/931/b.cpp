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

void Solution() {
    ll n, a, b, ctr = 0;
    cin >> n >> a >> b;
    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) A[i] = i + 1;
    auto winner = [&](ll &x, ll &y) -> ll {
        if ((x == a && y == b) || (x == b && y == a)) return 0LL;  // over
        if (x == a || y == a) return a;
        if (x == b || y == b) return b;
        return x;
    };
    while (sz(A) > 2) {
        ctr++;
        vector<ll> temp;
        for (ll i = 0; i < sz(A); i += 2) {
            ll t = winner(A[i], A[i + 1]);
            if (t == 0) return void(cout << ctr << '\n');
            temp.push_back(t);
        }
        A = temp;
    }
    cout << "Final!\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}