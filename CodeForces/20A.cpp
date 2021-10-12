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
    string temp = "", a;
    vector<string> vv;
    cin >> a;
    for (ll i = 0; i < sz(a); ++i) {
        if (a[i] != '/') {
            temp += a[i];
        } else {
            if (temp != "") vv.push_back(temp);
            temp = "";
        }
    }
    if (temp != "") vv.push_back(temp);
    cout << "/";
    for (ll i = 0; i < sz(vv); ++i) {
        cout << vv[i];
        if (i != sz(vv) - 1) cout << "/";
    }
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