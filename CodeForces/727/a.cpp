// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll a, b;
    cin >> a >> b;
    vector<ll> ans = {b};
    while (b > a) {
        if (b % 10 == 1)
            b /= 10;
        else if (b % 2 == 0)
            b /= 2;
        else
            return void(cout << "NO\n");
        ans.push_back(b);
    }
    if (b != a) return void(cout << "NO\n");
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto &x : ans) cout << x << ' ';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}