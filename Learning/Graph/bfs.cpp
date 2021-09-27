#include <bits/stdc++.h>
using namespace std;

const int N = 1'00'000;  // maximum number of nodes
vector<int> adj[N];      //adjacency list
int dis[N];
bool pushed_in_queue[N];  // visited

int main() {
    int n;  // nodes
    cin >> n;
    int m;  // edges
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;  // represents edge between x and y
        // Undirected
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // lets say we have to run bfs from 1
    queue<int> q;
    q.push(1);  // fixed vertex
    dis[1] = 0;
    pushed_in_queue[1] = true;

    while (!q.empty()) {
        int node = q.front();  // currently visiting this node
        q.pop();               // dont want to visit this again

        // Go through all children
        for (int x : adj[node]) {
            if (pushed_in_queue[x] == true) continue;
            q.push(x);  //visit x later
            dis[x] = dis[node] + 1;
            pushed_in_queue[node] = true;  // to make sure we dont visit twice
        }
    }

    cout << dis[10];  // must be 3

    return 0;
}

/*
? Example:
10 10

1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
6 10
7 10
*/

// inside queue: [0] [1 1 1] [2 2 2 2 2] [3]