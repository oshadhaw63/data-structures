#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    // Add edge for undirected graph
    void addEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
    }

    // Add edge for directed graph
    void addDirectedEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1;
        }
    }

    // Remove edge
    void removeEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 0;
            adjMatrix[dest][src] = 0;
        }
    }

    // Display adjacency matrix
    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Check if edge exists
    bool hasEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            return adjMatrix[src][dest] == 1;
        }
        return false;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();

    return 0;
}