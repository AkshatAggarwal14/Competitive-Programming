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

ll ask(ll L, ll R) {
    cout << "? " << L << ' ' << R << endl;
    ll res;
    cin >> res;
    return res;
}

void Solution() {
    ll q[4];
    for (ll i = 0; i < 4; ++i) q[i] = ask(1, i + 2);
    vector<ll> v = {4, 8, 15, 16, 23, 42};
    do {
        ll ctr = 0;
        for (ll i = 0; i < 4; ++i)
            if (v[0] * v[i + 1] == q[i]) ctr++;
        if (ctr == 4) {
            cout << "! ";
            for (auto &x : v) cout << x << ' ';
            cout << endl;
            return;
        }
    } while (next_permutation(v.begin(), v.end()));
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}