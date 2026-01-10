#include <iostream>
#include <vector>
using namespace std;
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, adj, visited);
        }
    }
}
int main()
{
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "DFS Traversal: ";
    DFS(start, adj, visited);
    return 0;
}

