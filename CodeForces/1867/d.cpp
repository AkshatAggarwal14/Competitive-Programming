#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    int n, k;
    cin >> n >> k;
    vector<int> edges(n);
    for (int i = 0; i < n; ++i) {
        cin >> edges[i], --edges[i];
    }

    if (k == 1) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        if (edges != a) return void(cout << "NO\n");
        cout << "YES\n";
        return;
    }

    vector<bool> visit(n);
    vector<int> indegree(n);

    for (int edge : edges) {
        if (edge != -1) {
            indegree[edge]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        visit[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            int neighbor = edges[i];
            int count = 1;
            visit[i] = true;
            while (neighbor != i) {
                visit[neighbor] = true;
                count++;
                neighbor = edges[neighbor];
            }
            if (count != k) return void(cout << "NO\n");
        }
    }

    cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
