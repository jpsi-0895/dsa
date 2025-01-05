The **Minimum Spanning Tree (MST)** algorithm is used to find a subset of edges in a weighted, undirected graph that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.

### Key Properties:
1. **Spanning Tree**: A tree that connects all the vertices in the graph.
2. **Minimum Weight**: Among all possible spanning trees, the MST has the smallest sum of edge weights.

### Common Algorithms to Find MST:
1. **Kruskal's Algorithm**
2. **Prim's Algorithm**

Let's briefly look at each:

---

### 1. **Kruskal's Algorithm**:
Kruskal's algorithm is a **greedy algorithm** that works by:
- Sorting all the edges in the graph by weight.
- Iterating through the edges and adding them to the MST, provided they don't form a cycle (this is done using a **Union-Find data structure**).
- The algorithm stops when exactly \(V-1\) edges have been added to the MST, where \(V\) is the number of vertices in the graph.

#### Steps:
1. Sort the edges in ascending order by their weight.
2. Initialize the MST as an empty set of edges.
3. Use a **Union-Find (Disjoint Set Union)** structure to detect cycles.
4. For each edge, if it connects two different components (i.e., no cycle is formed), add it to the MST.
5. Stop when the MST has \(V-1\) edges.

#### Time Complexity:
- Sorting edges: \(O(E \log E)\), where \(E\) is the number of edges.
- Union-Find operations: \(O(\alpha(E))\), where \(\alpha\) is the inverse Ackermann function, which grows very slowly.
- Overall: \(O(E \log E)\)

---

### 2. **Prim's Algorithm**:
Prim's algorithm is also a **greedy algorithm**, but it starts with a single vertex and grows the MST one edge at a time by adding the shortest edge that connects a vertex in the MST to one outside it.

#### Steps:
1. Start with any vertex and add it to the MST.
2. Choose the smallest weight edge that connects a vertex in the MST to a vertex outside it.
3. Add this edge to the MST and mark the vertex as visited.
4. Repeat steps 2 and 3 until the MST contains \(V-1\) edges.

#### Time Complexity:
- Using an **adjacency matrix** and simple arrays: \(O(V^2)\).
- Using a **min-priority queue** (implemented with a Fibonacci heap): \(O(E + V \log V)\), where \(E\) is the number of edges and \(V\) is the number of vertices.

---

### Comparison:
- **Kruskal's Algorithm** works well for sparse graphs and is easier to implement using a Union-Find data structure.
- **Prim's Algorithm** is more efficient when working with dense graphs, especially when using a priority queue to keep track of the next smallest edge.

Both algorithms are guaranteed to give the minimum spanning tree, but they differ in their approach to constructing it.

Here's an implementation of both **Kruskal's** and **Prim's** algorithms for finding the Minimum Spanning Tree (MST) in C++.

### 1. **Kruskal's Algorithm** (using Union-Find data structure)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Disjoint-Set Union-Find (DSU) with path compression and union by rank
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

// Kruskal's algorithm to find the MST
int kruskal(int V, vector<Edge>& edges) {
    UnionFind uf(V);
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.weight < b.weight; });

    int mst_weight = 0;
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            mst_weight += weight;
        }
    }

    return mst_weight;
}

int main() {
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mst_weight = kruskal(V, edges);
    cout << "Weight of MST (Kruskal's Algorithm): " << mst_weight << endl;

    return 0;
}
```

### Explanation:
- **UnionFind** class: Used for efficiently finding and uniting sets of vertices to detect cycles.
- **kruskal function**: Sorts the edges by their weight and adds them to the MST using Union-Find to check if adding an edge forms a cycle.

### 2. **Prim's Algorithm** (using a priority queue)

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // Prim's algorithm to find the MST
    int prim() {
        vector<int> key(V, INT_MAX);  // Key values to pick minimum weight edge
        vector<bool> inMST(V, false);  // To check if vertex is included in MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap for picking edge with min weight

        key[0] = 0;
        pq.push({0, 0});  // Start from vertex 0

        int mst_weight = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            mst_weight += key[u];

            // Update the key value of adjacent vertices
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        return mst_weight;
    }

private:
    int V;
    vector<vector<pair<int, int>>> adjList; // Adjacency list to represent graph
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    int mst_weight = g.prim();
    cout << "Weight of MST (Prim's Algorithm): " << mst_weight << endl;

    return 0;
}
```

### Explanation:
- **Graph class**: Represents the graph using an adjacency list.
- **prim function**: Uses a priority queue (min-heap) to efficiently find the next smallest edge that can be added to the MST.
- **Edge Relaxation**: For each vertex, the function updates the key values (minimum weights) for its adjacent vertices.

### Output:
Both implementations should return the weight of the MST for the provided graph.

For the given graph:
```
Edges: { (0,1,10), (0,2,6), (0,3,5), (1,3,15), (2,3,4) }
```
The weight of the MST will be **19**, as the selected edges for the MST are:
- (0, 3, 5)
- (2, 3, 4)
- (0, 1, 10)

---

### Time Complexity:
- **Kruskal's Algorithm**: \(O(E \log E)\), where \(E\) is the number of edges (due to sorting).
- **Prim's Algorithm**: \(O(E \log V)\), where \(E\) is the number of edges and \(V\) is the number of vertices (due to the priority queue).