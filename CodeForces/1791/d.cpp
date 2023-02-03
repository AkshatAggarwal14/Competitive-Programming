#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c1(26, 0), c2(26, 0);
    for (auto &x : s) ++c1[x - 'a'];
    int ans = 0;
    for (auto &x : s) {
        --c1[x - 'a'];
        ++c2[x - 'a'];
        int tans = 0;
        for (int j = 0; j < 26; ++j) tans += (c1[j] != 0) + (c2[j] != 0);
        ans = max(ans, tans);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}