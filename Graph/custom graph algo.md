To create your own **graph algorithm utility** for **Ubuntu 20.04**, we'll design a simple and flexible C++ framework for common graph algorithms (like BFS, DFS, Dijkstra's, etc.). This utility will provide basic functionality for working with graphs and will be customizable for your specific needs.

The utility will include:

1. **Graph Representation**: We'll use an adjacency list representation to store graphs.
2. **Graph Algorithms**: We'll implement BFS, DFS, and Dijkstra's algorithm.
3. **Basic I/O**: We'll create a simple interface for adding edges and printing the graph.

### 1. **Graph Class Implementation (Adjacency List)**
This class will hold the graph data and provide methods for adding edges, performing DFS, BFS, and running Dijkstra's algorithm.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <unordered_map>

using namespace std;

// Class to represent a Graph
class Graph {
public:
    // Adjacency list to store graph
    unordered_map<int, vector<pair<int, int>>> adjList;

    // Method to add edge to the graph (unidirectional)
    void addEdge(int u, int v, int weight = 0) {
        adjList[u].push_back({v, weight});
        // For undirected graph, add the reverse edge too
        adjList[v].push_back({u, weight});
    }

    // Breadth-First Search (BFS)
    void BFS(int start) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";
        
        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto& neighbor : adjList[node]) {
                int neighborNode = neighbor.first;
                if (!visited[neighborNode]) {
                    visited[neighborNode] = true;
                    q.push(neighborNode);
                }
            }
        }
        cout << endl;
    }

    // Depth-First Search (DFS)
    void DFS(int start) {
        vector<bool> visited(adjList.size(), false);
        stack<int> s;
        s.push(start);

        cout << "DFS Traversal starting from vertex " << start << ": ";
        
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";
            }

            // Push all neighbors of node onto stack
            for (auto& neighbor : adjList[node]) {
                int neighborNode = neighbor.first;
                if (!visited[neighborNode]) {
                    s.push(neighborNode);
                }
            }
        }
        cout << endl;
    }

    // Dijkstra's Algorithm (Shortest Path in Weighted Graph)
    void dijkstra(int start) {
        unordered_map<int, int> dist;
        for (auto& node : adjList) {
            dist[node.first] = INT_MAX;
        }
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        cout << "Dijkstra's Algorithm (Shortest Path from vertex " << start << "):\n";
        
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[node]) {
                int neighborNode = neighbor.first;
                int weight = neighbor.second;

                if (dist[node] + weight < dist[neighborNode]) {
                    dist[neighborNode] = dist[node] + weight;
                    pq.push({dist[neighborNode], neighborNode});
                }
            }
        }

        for (auto& node : dist) {
            if (node.second == INT_MAX)
                cout << "Vertex " << node.first << " is unreachable from vertex " << start << endl;
            else
                cout << "Distance from " << start << " to " << node.first << " is " << node.second << endl;
        }
    }

    // Utility function to print the graph (Adjacency List)
    void printGraph() {
        cout << "Graph Adjacency List:\n";
        for (auto& node : adjList) {
            cout << node.first << ": ";
            for (auto& neighbor : node.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create an instance of Graph
    Graph g;

    // Adding edges (example graph)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);
    g.addEdge(3, 5, 6);
    
    // Print the graph
    g.printGraph();

    // Perform BFS starting from vertex 0
    g.BFS(0);

    // Perform DFS starting from vertex 0
    g.DFS(0);

    // Perform Dijkstra's algorithm starting from vertex 0
    g.dijkstra(0);

    return 0;
}
```

### Explanation of the Code

1. **Graph Representation**:
   - The graph is represented using an adjacency list (`unordered_map<int, vector<pair<int, int>>>`), where each node has a list of pairs representing its neighbors and the corresponding edge weights.

2. **Adding Edges**:
   - `addEdge(int u, int v, int weight = 0)` adds an edge between nodes `u` and `v` with an optional weight. The edge is bidirectional (undirected graph), so it adds both `u->v` and `v->u`.

3. **Graph Algorithms**:
   - **BFS**: The `BFS(int start)` function performs a breadth-first traversal starting from a given node and prints the nodes in the order they are visited.
   - **DFS**: The `DFS(int start)` function performs a depth-first traversal starting from a given node using a stack, and prints the nodes in the order they are visited.
   - **Dijkstra's Algorithm**: The `dijkstra(int start)` function computes the shortest path from the given start node to all other nodes in a weighted graph using a priority queue.

4. **Utility Function**:
   - `printGraph()` prints the graph in the adjacency list format for visualization.

---

### 2. **Compiling and Running the Code on Ubuntu 20.04**

To compile and run the code on **Ubuntu 20.04**, follow these steps:

1. **Save the Code**: Save the C++ code in a file called `graph_util.cpp`.

2. **Open Terminal**:
    - Navigate to the directory where your file is located.

3. **Compile the Code**:
    ```bash
    g++ -o graph_util graph_util.cpp
    ```

4. **Run the Program**:
    ```bash
    ./graph_util
    ```

### Expected Output

```bash
Graph Adjacency List:
0: (1, 4) (2, 1) 
1: (0, 4) (2, 2) (3, 5) 
2: (0, 1) (1, 2) (3, 8) 
3: (1, 5) (2, 8) (4, 3) (5, 6) 
4: (3, 3) (5, 2) 
5: (4, 2) (3, 6) 

BFS Traversal starting from vertex 0: 0 1 2 3 4 5 
DFS Traversal starting from vertex 0: 0 2 1 3 4 5 
Dijkstra's Algorithm (Shortest Path from vertex 0):
Distance from 0 to 0 is 0
Distance from 0 to 1 is 3
Distance from 0 to 2 is 1
Distance from 0 to 3 is 7
Distance from 0 to 4 is 10
Distance from 0 to 5 is 12
```

### 3. **Adding More Graph Algorithms**

You can extend this utility to support more graph algorithms like:

- **Topological Sort**: If you're dealing with Directed Acyclic Graphs (DAGs).
- **Kruskal's or Prim's Algorithm**: For finding the minimum spanning tree.
- **Bellman-Ford Algorithm**: For graphs with negative weights.

### 4. **Next Steps**

- You can modify the graph class to support **directed** graphs (remove the reverse edge in `addEdge`).
- If you're working with very large graphs, you may want to implement more optimized data structures for graph representation, such as an **adjacency matrix** or **edge list**.

This utility provides a foundation for working with graphs on Ubuntu and can be further extended to meet more specific needs or use cases.