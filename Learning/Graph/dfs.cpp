#include <bits/stdc++.h>
using namespace std;

const int N = 1'00'000;  // maximum number of nodes
vector<int> adj[N];      //adjacency list
bool visited[N];
int cnt;

void dfs(int node) {
    // mark it blue
    visited[node] = true;
    cnt++;
    for (int x : adj[node]) {
        if (!visited[x]) dfs(x);
    }
}

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
    dfs(1);  // dfs from any node
    if (n == cnt) {
        // connected graph
        cout << "Connected! :)";
    } else {
        // not connected
        cout << "Not Connected :(";
    }
    return 0;
}