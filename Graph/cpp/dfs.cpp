#include <iostream>
#include <vector>

using namespace std;

class DFS
{
private:
    int v;
    vector<vector<int>> adj;

    void DFSUtil(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
        // cout << endl;
    }

public:
    DFS(int v)
    {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSuse(int start)
    {
        vector<bool> visited(v, false);
        DFSUtil(start, visited);
    }
};

int main()
{
    DFS g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS starting from node 0: ";
    g.DFSuse(0);

    cout << endl;
    return 0;
}