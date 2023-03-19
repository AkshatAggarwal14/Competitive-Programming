#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    bool c1[26], c2[26];
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (i & 1)
            c1[c - 'a'] = true;
        else
            c2[c - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
        if (c1[i] && c2[i]) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}