# Graphs
A Graph is a non-linear data structure consisting of nodes and edges. The nodes are sometimes also referred to as vertices and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph can be defined as,
> A Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes.

Graphs are used to solve many real-life problems. Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network.

> A path in a graph is a finite or infinite sequence of edges which joins a sequence of vertices which, by most definitions, are all distinct (and since the vertices are distinct, so are the edges). A directed path (sometimes called `dipath[1]`) in a directed graph is a finite or infinite sequence of edges which joins a sequence of distinct vertices, but with the added restriction that the edges be all directed in the same direction. 

Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender, locale etc.

### Example 
If the following graph represents a network of friends, then 
- Node 2 and 1 are friends
- Node 2 and 4 aren't (they are mutual friends of 1 and 3)

<!-- ![Graph](Images/graph.png) -->
<p align="center">
  <img src="Images/graph.png" alt="Graph"/>
</p>


In the above undirected Graph, the set of vertices `V = {0,1,2,3,4}` and the set of edges `E = {(1, 0), (0, 4), (1, 4), (1, 3), (3, 4), (1, 2), (3, 2)}`.

## Representations

A graph is a data structure that consists of the following two components: 
1. A finite set of vertices also called as nodes. 
2. A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(di-graph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.


The following two are the most commonly used representations of a graph. 
1. Adjacency Matrix 
2. Adjacency List 
There are other representations also like, Incidence Matrix and Incidence List. The choice of graph representation is situation-specific. It totally depends on the type of operations to be performed and ease of use. 

### Adjacency Matrix
- Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. 

- Let the 2D array be `adj[][]`, a slot `adj[i][j] = 1` indicates that there is an edge from vertex i to vertex j. 

- Adjacency matrix for undirected graph is always `symmetric`. 

- Adjacency Matrix is also used to represent weighted graphs. If `adj[i][j] = w`, then there is an edge from vertex i to vertex j with weight w. 

The adjacency matrix for the above example graph is: 

<!-- ![Adjacency Matrix](Images/adjmatrix.png) -->
<p align="center">
  <img src="Images/adjmatrix.png" alt="Adjacency Matrix"/>
</p>

#### Pros
- Representation is easier to implement and follow. 
- Removing an edge takes `O(1)` time. 
- Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done `O(1)`.

#### Cons
- Consumes more space `O(N^2)`. Even if the graph is sparse(contains less number of edges), it consumes the same space. 
- Adding a vertex is `O(N^2)` time. 

### Adjacency List: 
- An array of lists is used. The size of the array is equal to the number of vertices. 

- Let the array be an `array[]`. An entry `array[i]` represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. 

The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above graph:

<!-- ![Adjacency List](Images/adjlist.png) -->
<p align="center">
  <img src="Images/adjlist.png" alt="Adjacency List"/>
</p>

#### Pros
- Saves space `O(|V|+|E|)` OR `O(2M)` where M is number of edges.
- In the worst case, there can be `C(V, 2)` number of edges in a graph thus consuming `O(N^2)` space. 
- Adding a vertex is easier.

#### Cons 
- Queries like whether there is an edge from vertex u to vertex v are not efficient and can be done `O(N)`.

# Important Terms:

-   Two nodes are ![formula](https://render.githubusercontent.com/render/math?math=connected) if there exists a path between them. Example: `1->2->3->4`, 1 and 4 are connected
  Thus connectivity is defined based on path

-   ![formula](https://render.githubusercontent.com/render/math?math=Cycle): We come back to the same node without repeating. Example: `1->2->3->4->1`

-   ![formula](https://render.githubusercontent.com/render/math?math=Distance): Number of edges between 2 connected nodes (on the path). Example: `1->2->3->4`, distance is 3

## Types of graph:
  -
    -   ![formula](https://render.githubusercontent.com/render/math?math=Undirected-Graph): Edges are non directional. Example: Brother 1 <-> Brother 2 (Bidirectional relationship) [1 -- 2]
    
    -   ![formula](https://render.githubusercontent.com/render/math?math=Directed-Graph): Edges are directional. Example: Father -> Son (Unidirectional) 1 --> 2

<br/>

  -  
    -   ![formula](https://render.githubusercontent.com/render/math?math=Weighted-Graph): Edges have weights. Example: Flight route with cost of edges    

    -    ![formula](https://render.githubusercontent.com/render/math?math=Unweighted-Graph): Normal Edges

<br/>


  - 
    - ![formula](https://render.githubusercontent.com/render/math?math=Cyclic-Graph): If the graph has atleast one cycle
    
    - ![formula](https://render.githubusercontent.com/render/math?math=Acyclic-Graph): otherwise

<br/>

  -
    - ![formula](https://render.githubusercontent.com/render/math?math=Connected-Graph): Path from any node to any other node
    -  ![formula](https://render.githubusercontent.com/render/math?math=Disconnected-Graph): Otherwise, A disconnected graph will have multiple connected components.

<br/>

## Trees and Forests:
  -   Both are Acyclic. No cycle is allowed.
  -   ![formula](https://render.githubusercontent.com/render/math?math=Tree)    - Graph is connected.
      <br>![formula](https://render.githubusercontent.com/render/math?math=Forest)  - Graph is disconnected.
  -   Thus forest has different components. Forests are collection of trees, Thus its name.

### Connected components: 
1. In a connected component, all nodes are connected to each other.

2. A connected component needs to be maximal. (Should not be a part of something bigger)

# Connectivity Check

> Tell if a given graph is connected or not.

If we start along some vertex, and follow the edges, we must be able to reach all other vertices.

### How to store a graph in a program?

> We need to know which vertex is connected to which others

1. Adjacency Matrix, `adj[][]` (Discussed above)
2. Adjacency List (Discussed above) `[Uses less memory]`

<p align="center">
  <img src="Images/g1.png" alt="Graph"/>
</p>

### DFS (Depth First Search)

We can mark the uncoloured nodes with some color and count how many we marked in total, if it is equal to number of nodes then the graph is connected
> Just like throwing popcorn in maze to find out the exit<br><br> A grid is just like a graph, with positions we can move to representing the nodes.


<p align="center">
  <img src="Images/dfs-intro.png" alt="Graph"/>
</p>

#### Algorithm: 
```py
count = 0

dfs(node):
    color[node] = blue; count++
     # Takes list for a vertex from adj list
    for X in adj[node]:  
        if color[X] = blue:
            continue
        # Recursively go through all connected nodes
        dfs(X)
```

#### Code (C++):

```cpp
const int N = 1'00'000;  // maximum number of nodes
vector<int> adj[N];      //adjacency list
bool visited[N];
int cnt;

void dfs(int node) {
    // mark it blue
    visited[node] = true;
    cnt++;
    for (int x : adj[node]) {
        if (visited[x]) continue;
        dfs(x);
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
        adj[x].push_back(y);
        adj[y].push_back(x);
        // As undirected so both edges
    }
    dfs(1);  // dfs from any node
    if (n == cnt) {
        // connected graph
    } else {
        // not connected
    }
    return 0;
}
```