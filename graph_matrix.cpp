#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        // For undirected graph, uncomment the line below
        // adjList[dest].push_back(src);
    }

    // Display the adjacency list
    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Get adjacent vertices of a given vertex
    vector<int> getAdjacent(int vertex) {
        return adjList[vertex];
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Display the graph
    cout << "Graph Adjacency List Representation:" << endl;
    g.display();

    return 0;
}