#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &A : a) cin >> A;
        string ans(m, 'B');
        for (int i = 0; i < n; ++i) {
            int x = a[i] - 1, y = m - a[i];
            if (x > y) swap(x, y);
            if (ans[x] != 'A') {
                ans[x] = 'A';
            } else {
                ans[y] = 'A';
            }
        }
        cout << ans << '\n';
    }
}