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
    ll n;
    cin >> n;
    map<ll, ll> cnt;
    vector<ll> a(n);
    bool flag2, flag1;
    flag2 = flag1 = false;
    for (ll &x : a) {
        cin >> x, ++cnt[x];
        if (cnt[x] > 2) flag2 = true;
        if (cnt[x] > 1) flag1 = true;
    }
    if (flag2) return void(cout << "-1\n");
    if (!flag1) {
        sort(a.rbegin(), a.rend());
        for (ll &x : a) cout << x << ' ';
        cout << '\n';
        return;
    }
    ll mx = *max_element(a.begin(), a.end());
    if (count(a.begin(), a.end(), mx) == 2) return void(cout << "-1\n");
    for (auto &[x, y] : cnt)
        if (y == 2) cout << x << ' ', y--;
    vector<ll> remain;
    for (auto &[x, y] : cnt)
        if (y == 1) remain.push_back(x);
    sort(remain.rbegin(), remain.rend());
    for (auto &x : remain) cout << x << ' ';
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}