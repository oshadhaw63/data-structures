#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int vertices;
    vector<list<int>> adjList;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add edge to the graph
    void addEdge(int src, int dest, bool bidirectional = true) {
        adjList[src].push_back(dest);
        if (bidirectional) {
            adjList[dest].push_back(src);
        }
    }

    // Display the adjacency list
    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Remove edge from the graph
    void removeEdge(int src, int dest) {
        adjList[src].remove(dest);
        adjList[dest].remove(src);
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

    cout << "Graph Adjacency List:" << endl;
    g.display();

    return 0;
}