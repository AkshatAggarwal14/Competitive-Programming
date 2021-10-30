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
    vector<ll> parent(n + 1, -1), child(n + 1, -1), temp;
    for (ll i = 1; i <= n; ++i) parent[i] = i;
    while (q--) {
        cin >> type;
        if (type == 3) {
            cin >> x;
            temp.clear();
            while (x != parent[x]) x = parent[x];
            while (child[x] != -1) {
                temp.push_back(x);
                x = child[x];
            }
            temp.push_back(x);
            cout << sz(temp) << ' ';
            for (ll &ele : temp) cout << ele << ' ';
            cout << '\n';
        } else {
            cin >> x >> y;
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