// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
constexpr auto sz = [](const auto &container) -> int { return int(container.size()); };

const int SPECIAL = -1;

// identify each square from top left corner.
// start from the end, where we have the last 2x2 square
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid)
        for (auto &cell : row) cin >> cell;

    vector<array<int, 3>> ans;
    queue<pair<int, int>> bfs;

    auto insert = [&](int i, int j) -> void {
        // check valid_square
        if (i < 0 || i >= n - 1 || j < 0 || j >= m - 1) return;
        set<int> st;
        for (int dx = 0; dx <= 1; ++dx)
            for (int dy = 0; dy <= 1; ++dy)
                if (grid[i + dx][j + dy] != SPECIAL)
                    st.insert(grid[i + dx][j + dy]);
        if (sz(st) != 1) return;             // only 1 color except special cells
        ans.push_back({i, j, *st.begin()});  // push in ans
        for (int dx = 0; dx <= 1; ++dx)
            for (int dy = 0; dy <= 1; ++dy)
                if (grid[i + dx][j + dy] != SPECIAL)  //!
                    bfs.emplace(i + dx, j + dy), grid[i + dx][j + dy] = SPECIAL;
    };

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m - 1; ++j)
            insert(i, j);  // check all and push valid
    while (!bfs.empty()) {
        auto [i, j] = bfs.front();
        bfs.pop();
        for (int dx = -1; dx <= 0; ++dx)
            for (int dy = -1; dy <= 0; ++dy)
                insert(i + dx, j + dy);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] != -1) return cout << "-1\n", 0;
    reverse(ans.begin(), ans.end());
    cout << sz(ans) << '\n';
    for (auto &[i, j, c] : ans) cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';

    return 0;
}