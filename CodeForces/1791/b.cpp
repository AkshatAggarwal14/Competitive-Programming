#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, y = 0;
    string s;
    cin >> n >> s;
    bool check = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            ++y;
        } else if (s[i] == 'D') {
            --y;
        } else if (s[i] == 'L') {
            --x;
        } else {
            ++x;
        }
        if (x == 1 && y == 1) return void(cout << "YES\n");
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}