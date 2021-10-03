#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<vector<int>> &adj, int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<vector<int>> adj) {
    for (int d = 0; d < (int)adj.size(); ++d) {
        cout << "Vertex " << d;
        for (auto x : adj[d]) cout << " -> " << x;
        cout << '\n';
    }
}

int main() {
    int V = 4;

    // Create a graph
    vector<vector<int>> adj(V);

    // Add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    printGraph(adj);
}