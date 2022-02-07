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
    set<ll> pos;  // for -1s
    const ll N = (1LL << 20);
    for (ll i = 0; i < N; ++i) pos.insert(i);
    vector<ll> A(N, -1);
    ll q, t, x, original;
    cin >> q;
    while (q--) {
        cin >> t >> x;
        original = x;
        x %= N;
        if (t == 1) {
            auto last = pos.lower_bound(x);
            if (last == pos.end()) last = pos.begin();
            A[*last] = original;
            pos.erase(*last);
        } else {
            cout << A[x] << '\n';
        }
    }
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
    return 0;
}