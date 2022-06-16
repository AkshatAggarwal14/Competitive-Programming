#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()

void Solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --v, --u;
        g[u].push_back(v), g[v].push_back(u);
    }
    const auto BFS = [&](int source) -> vector<int> {
        vector<int> bfs(n, -1), d(n, -1);
        int start = 0, end = 0;
        d[start] = 0;
        bfs[end++] = source;
        while (start < end) {
            int parent = bfs[start];
            start++;  // pop
            for (int &child : g[parent]) {
                if (d[child] != -1) continue;
                d[child] = (d[parent] ^ 1);
                bfs[end++] = child;
            }
        }
        return d;
    };
    // out of 2 colors there will be 1 <= n/2 as even/odd distance, and each has other color vertices connected to it, thus fulfills conditions
    vector<int> color(BFS(0));
    int good_col = 0;
    if (count(all(color), 0) > n / 2) good_col = 1;
    cout << count(all(color), good_col) << '\n';
    for (int i = 0; i < n; ++i)
        if (color[i] == good_col) cout << i + 1 << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}