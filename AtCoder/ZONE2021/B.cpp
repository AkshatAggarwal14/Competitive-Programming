#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

void Solution() {
    /*
        H/(D+y) = (hi)/(di+y) = (x/y)
    */
    ll N, D, H, d, h;
    cin >> N >> D >> H;
    auto get = [&](ll &dd, ll &hh) -> double { return double(hh * D - H * dd) / double(D - dd); };
    double ans = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> d >> h;
        ans = max(ans, get(d, h));
    }
    cout << ans << '\n';
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