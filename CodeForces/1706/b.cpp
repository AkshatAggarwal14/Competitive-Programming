#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> pos(n + 1);
        for (int i = 0; auto &A : a) cin >> A, pos[A].push_back(i++);
        for (int i = 1; i <= n; ++i) {
            int cnt = !!(pos[i].size());
            for (int j = 1; j < int(pos[i].size()); ++j)
                if ((pos[i][j] - pos[i][j - 1]) & 1)
                    ++cnt;
            cout << cnt << ' ';
        }
        cout << '\n';
    }
}