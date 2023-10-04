//Given a connected, weighted graph G with n vertices and m edges,fund a maximum spanning tree for G.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set element
struct DisjointSetElement {
    int parent;
    int rank;
};

class Graph {
private:
    int V;  // Number of vertices
    vector<Edge> edges; // Edges in the graph

public:
    Graph(int V);
    void addEdge(int src, int dest, int weight);
    vector<Edge> kruskalMST();
    int findParent(vector<DisjointSetElement>& disjointSet, int vertex);
    void unionSets(vector<DisjointSetElement>& disjointSet, int src, int dest);
};

Graph::Graph(int V) {
    this->V = V;
}

void Graph::addEdge(int src, int dest, int weight) {
    edges.push_back({src, dest, weight});
}

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int Graph::findParent(vector<DisjointSetElement>& disjointSet, int vertex) {
    if (disjointSet[vertex].parent != vertex)
        disjointSet[vertex].parent = findParent(disjointSet, disjointSet[vertex].parent);
    return disjointSet[vertex].parent;
}

void Graph::unionSets(vector<DisjointSetElement>& disjointSet, int src, int dest) {
    int srcParent = findParent(disjointSet, src);
    int destParent = findParent(disjointSet, dest);

    if (disjointSet[srcParent].rank < disjointSet[destParent].rank)
        disjointSet[srcParent].parent = destParent;
    else if (disjointSet[srcParent].rank > disjointSet[destParent].rank)
        disjointSet[destParent].parent = srcParent;
    else {
        disjointSet[destParent].parent = srcParent;
        disjointSet[srcParent].rank++;
    }
}

vector<Edge> Graph::kruskalMST() {
    vector<Edge> result;
    vector<DisjointSetElement> disjointSet(V);

    // Initialize disjoint set
    for (int i = 0; i < V; i++) {
        disjointSet[i].parent = i;
        disjointSet[i].rank = 0;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    for (Edge edge : edges) {
        int srcParent = findParent(disjointSet, edge.src);
        int destParent = findParent(disjointSet, edge.dest);

        if (srcParent != destParent) {
            result.push_back(edge);
            unionSets(disjointSet, srcParent, destParent);
        }
    }

    return result;
}

int main() {
    Graph graph(4); // Number of vertices: 4

    // Adding edges to the graph
    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 4);

    vector<Edge> minSpanningTree = graph.kruskalMST();

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (Edge edge : minSpanningTree)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;

    return 0;
}
