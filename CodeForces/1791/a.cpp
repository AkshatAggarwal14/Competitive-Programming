#include <bits/stdc++.h>
using namespace std;

void solve() {
    char c;
    cin >> c;
    cout << (("codeforces"s.find(c) != string::npos) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}