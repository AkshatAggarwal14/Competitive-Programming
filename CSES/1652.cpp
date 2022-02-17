/*
    |----|---|
    | a  | b |
    |----|---|
    | c  | d |
    |----|---|
    area of d = (a + b + c + d) - ((a + c) + (a + b) - a)
    how to get count of something from top?
    use 2D pref sum
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto &row : grid)
        for (auto &c : row) cin >> c;
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (grid[i - 1][j - 1] == '*');
    while (q--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}