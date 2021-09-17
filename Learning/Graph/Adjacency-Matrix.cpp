// Adjacency Matrix representation in C++

#include <bits/stdc++.h>
using namespace std;

class Graph {
   private:
    bool** adjMatrix;  // boolean matrix
    int numVertices;

   public:
    Graph(int n) {
        this->numVertices = n;
        adjMatrix = new bool*[n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new bool[n];
            for (int j = 0; j < n; j++)
                adjMatrix[i][j] = false;
        }
    }

    // Add edges
    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    // Print the martix
    void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.toString();
}