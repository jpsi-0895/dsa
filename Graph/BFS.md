### BFS (Breadth-First Search) in C++

**Breadth-First Search (BFS)** is a graph traversal algorithm that explores the vertices of a graph level by level, starting from a given source vertex. It explores all the neighbors of a vertex before moving on to their neighbors. BFS is commonly used to find the shortest path in an unweighted graph, check connectivity, and more.

### Key Features:
1. BFS uses a **queue** to keep track of the nodes to be explored.
2. It explores all the vertices at the current level before moving to the next level.
3. BFS is ideal for unweighted graphs to find the shortest path.

### Algorithm Steps:
1. Start at the source node and mark it as visited.
2. Enqueue the source node into the queue.
3. While the queue is not empty:
   - Dequeue a node.
   - Visit all its unvisited neighbors, mark them as visited, and enqueue them into the queue.
4. Repeat until all nodes are visited.

### Time Complexity:
- **O(V + E)**, where \(V\) is the number of vertices and \(E\) is the number of edges in the graph.

### Space Complexity:
- **O(V)**, due to the space used by the queue and the visited array.

### C++ Code for BFS:

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list representation of the graph
    
    // Constructor to initialize the graph
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }
    
    // Function to add an edge between vertex u and vertex v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Assuming the graph is undirected
    }
    
    // BFS function to traverse the graph starting from a source vertex
    void BFS(int start) {
        vector<bool> visited(V, false); // To keep track of visited nodes
        queue<int> q; // Queue for BFS
        
        // Start with the source vertex
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " "; // Visit the current node
            
            // Enqueue all unvisited neighbors of the current node
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices (0 to 5)
    Graph g(6);
    
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    cout << "BFS starting from vertex 0: ";
    g.BFS(0); // Start BFS from vertex 0
    
    return 0;
}
```

### Explanation:

1. **Graph Class**:
   - The class represents an undirected graph using an adjacency list.
   - The `addEdge` method adds an edge between two vertices, \(u\) and \(v\), to the graph.
   - The `BFS` method performs the Breadth-First Search starting from a given vertex (`start`). It uses a queue to manage the traversal and a `visited` array to ensure that nodes are not visited more than once.

2. **BFS Traversal**:
   - The BFS starts by marking the `start` node as visited and enqueuing it.
   - In a loop, the algorithm dequeues a node, visits it (prints it), and enqueues all its unvisited neighbors.
   - This continues until all reachable nodes have been visited.

3. **Main Function**:
   - A graph with 6 vertices (numbered 0 to 5) is created, and edges are added.
   - BFS is then executed starting from vertex 0.

### Output:

```
BFS starting from vertex 0: 0 1 2 3 4 5
```

### Explanation of the Output:

The graph used in this example looks like this:

```
    0
   / \
  1   2
 / \   \
3   4   5
```

- Starting from vertex 0, BFS explores all the neighbors at the same level before moving deeper.
- From vertex 0, BFS visits vertices 1 and 2, then it visits their neighbors 3, 4, and 5.

### Use Cases of BFS:
- **Shortest Path**: In unweighted graphs, BFS can be used to find the shortest path between two nodes.
- **Level Order Traversal**: BFS is used in tree data structures to print nodes level by level.
- **Connectivity**: BFS can be used to check if a graph is connected, meaning all vertices are reachable from a starting vertex.
- **Cycle Detection**: In an undirected graph, BFS can also be used for cycle detection.

### Summary:
- **BFS** is an effective algorithm for exploring graphs level by level.
- It uses a **queue** to manage the order of nodes to be explored.
- The time complexity is \(O(V + E)\), making it efficient for large graphs.