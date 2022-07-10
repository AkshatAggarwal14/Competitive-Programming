#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    int LG = __lg(n);
    vector<vector<int>> up(n + 1, vector<int>(LG, -1));
    up[1][0] = -1;
    for (int i = 2; i <= n; ++i) cin >> up[i][0];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= LG; ++j) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        for (int i = LG; i >= 0; --i) {
            if (a == -1 || b == 0) break;
            if (b >= (1 << i)) {
                a = up[a][i];
                b -= (1 << i);
            }
        }
        cout << a << '\n';
    }

    return 0;
}
