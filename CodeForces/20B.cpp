#ifndef ONLINE_JUDGE
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
    cout << fixed << setprecision(12);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) return void(cout << "-1\n");
    if (a == 0) {
        if (b != 0) {
            cout << "1\n";
            cout << (-c + 0.0) / (b + 0.0) << '\n';
        } else
            cout << 0 << '\n';
        return;
    }
    ll d = b * b - 4 * a * c;
    if (d < 0) return void(cout << "0\n");
    vector<double> ans;
    ans.push_back((-b + sqrt(d + 0.0)) / (2.0 * a));
    if (d) ans.push_back((-b - sqrt(d + 0.0)) / (2.0 * a));
    sort(ans.begin(), ans.end());
    cout << sz(ans) << '\n';
    for (auto x : ans) cout << x << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}