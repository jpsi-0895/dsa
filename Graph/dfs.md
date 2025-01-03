### Depth-First Search (DFS) in C++

DFS is an algorithm used for traversing or searching tree or graph data structures. It starts from a node and explores as far as possible along each branch before backtracking.

Here’s an implementation of DFS for a graph in C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS traversal starting from source node
    void DFS(int start) {
        // Vector to track visited nodes
        vector<bool> visited(V, false);
        
        // Start DFS from the given node
        DFSUtil(start, visited);
    }

private:
    // Utility function for recursive DFS
    void DFSUtil(int node, vector<bool>& visited) {
        // Mark the current node as visited
        visited[node] = true;
        cout << node << " "; // Print the current node

        // Visit all the adjacent unvisited nodes
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited); // Recur for the unvisited neighbor
            }
        }
    }
};

int main() {
    // Create a graph with 5 nodes (0 to 4)
    Graph g(5);

    // Add edges (undirected)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // Start DFS traversal from node 0
    cout << "DFS starting from node 0: ";
    g.DFS(0);

    return 0;
}
```

### Explanation of the Code:
1. **Graph Class**:
   - **V**: Represents the number of vertices in the graph.
   - **adj**: An adjacency list to store the graph. Each index in the list represents a vertex, and each element in the list represents a neighboring vertex.

2. **addEdge(u, v)**: Adds an undirected edge between the vertices `u` and `v`.

3. **DFS(start)**:
   - Initializes a `visited` vector to track which nodes have already been visited.
   - The DFS traversal is performed by calling the recursive helper function `DFSUtil()`.

4. **DFSUtil(node, visited)**:
   - Marks the current node as visited and prints it.
   - Recursively visits all the unvisited adjacent nodes.

5. **Main Function**:
   - A graph is created with 5 vertices (0 to 4), and edges are added.
   - DFS traversal is started from vertex 0.

### Output:
For the example graph:
```
  0
 / \
1   2
|   |
3   4
```
The DFS traversal starting from node `0` will be:
```
DFS starting from node 0: 0 1 3 4 2
```

This traversal visits nodes by going deeper into the graph before backtracking to visit the remaining unvisited nodes. The order of traversal depends on the adjacency list order.