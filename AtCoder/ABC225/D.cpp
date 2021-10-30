#include "bits/stdc++.h"
using namespace std;
auto sz = [](const auto &container) -> int { return int(container.size()); };

void Solution() {
    int n, q, type, x, y;
    cin >> n >> q;
    vector<int> parent(n + 1, -1), child(n + 1, -1), temp;
    for (int i = 1; i <= n; ++i) parent[i] = i;
    while (q--) {
        cin >> type;
        if (type == 3) {
            cin >> x;
            temp.clear();
            while (x != parent[x]) x = parent[x];  // go to the first car
            while (child[x] != -1) temp.push_back(x), x = child[x];
            temp.push_back(x);
            cout << sz(temp) << ' ';
            for (int &ele : temp) cout << ele << ' ';
            cout << '\n';
        } else {
            cin >> x >> y;
            if (type == 1)
                parent[y] = x, child[x] = y;
            else
                parent[y] = y, child[x] = -1;
        }
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}