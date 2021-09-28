#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
// #include <Akshat.hpp>

// Node and weight
vector<pair<int, int>> v[100005];
int d[100005];  // distance

int main() {
    int n, m;  // vertices, edges
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({y, w});
        v[y].push_back({x, w});
    }
    // initially all nodes at INF distance
    for (int i = 1; i <= n; ++i) d[i] = INF;

    // source is 1.
    d[1] = 0;
    // distance 1st so it is sorted
    set<pair<int, int>> s;  //{distance, node}
    s.insert({0, 1});
    while (!s.empty()) {
        int dis = s.begin()->first;
        int vertex = s.begin()->second;
        // dbg("Parent (Before erase): ", s);
        s.erase(s.begin());

        for (pair<int, int> x : v[vertex]) {
            int newDis = dis + x.second;
            int newVer = x.first;
            if (newDis < d[newVer]) {
                s.erase({d[newVer], newVer});
                d[newVer] = newDis;  // update
                s.insert({d[newVer], newVer});
                // dbg("Child (After update): ", s);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    return 0;
}

/*
5 5
1 4 100
1 3 200
2 1 100
5 2 200
3 5 300
*/

// 0 100 200 100 300
