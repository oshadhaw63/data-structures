#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        
        s.push(start);
        
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            
            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;
            }
            
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSRecursive(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }

private:
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    cout << "DFS (Iterative): ";
    g.DFS(0);
    
    cout << "DFS (Recursive): ";
    g.DFSRecursive(0);
    
    return 0;
}