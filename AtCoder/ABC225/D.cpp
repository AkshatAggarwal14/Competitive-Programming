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
    ll n, q, type, x, y;
    cin >> n >> q;
    vector<ll> parent(n), child(n);
    for (ll i = 0; i < n; ++i) parent[i] = i, child[i] = -1;
    while (q--) {
        cin >> type;
        dbg(parent, child);
        if (type == 3) {
            cin >> x;
            x--;

            ll start = x;
            vector<ll> temp;
            while (start != parent[start]) start = parent[start];
            while (child[start] != -1) {
                temp.push_back(start + 1);
                start = child[start];
            }
            temp.push_back(start + 1);

            cout << sz(temp) << ' ';
            for (ll &ele : temp) cout << ele << ' ';
            cout << '\n';
        } else {
            cin >> x >> y;
            x--, y--;
            if (type == 1) {
                parent[y] = x;
                child[x] = y;
            } else {
                parent[y] = y;
                child[x] = -1;
            }
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}