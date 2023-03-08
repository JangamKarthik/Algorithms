#include <iostream>

using namespace std;

const int MAX = 100; // Maximum number of vertices

bool adjMatrix[MAX][MAX]; // Adjacency matrix representation of graph

bool visited[MAX]; // Keep track of visited vertices

int parent[MAX]; // Keep track of parent vertices

// DFS traversal to find a cycle in the graph

bool dfs(int current, int numVertices) {

    // Mark the current vertex as visited

    visited[current] = true;

    // Visit all adjacent vertices of the current vertex

    for (int i = 0; i < numVertices; i++) {

        if (adjMatrix[current][i]) {

            // If the adjacent vertex is not visited, mark it as visited and recursively visit its neighbors

            if (!visited[i]) {

                parent[i] = current;

                if (dfs(i, numVertices)) {

                    return true;

                }

            } 

            // If the adjacent vertex is already visited and not the parent of the current vertex, a cycle exists

            else if (parent[current] != i) {

                return true;

            }

        }

    }

    // No cycle found, return false

    return false;

}

int main() {

    // Initialize adjacency matrix with zeros

    for (int i = 0; i < MAX; i++) {

        for (int j = 0; j < MAX; j++) {

            adjMatrix[i][j] = false;

        }

    }

    // Read input to build the graph

    int numVertices, numEdges;

    cout << "Enter the number of vertices and edges: ";

    cin >> numVertices >> numEdges;

    cout << "Enter the edges in the format 'u v': " << endl;

    for (int i = 0; i < numEdges; i++) {

        int u, v;

        cin >> u >> v;

        // Add edge to adjacency matrix

        adjMatrix[u][v] = true;

       // adjMatrix[v][u] = true; // Uncomment this line for an undirected graph

    }

    // Initialize visited array and parent array to -1

    for (int i = 0; i < numVertices; i++) {

        visited[i] = false;

        parent[i] = -1;

    }

    // Perform DFS traversal to find a cycle in the graph

    bool hasCycle = false;

    for (int i = 0; i < numVertices; i++) {

        if (!visited[i]) {

            if (dfs(i, numVertices)) {

                hasCycle = true;

                break;

            }

        }

    }

    // Print whether a cycle exists or not

    if (hasCycle) {

        cout << "The graph has a cycle" << endl;

    } else {

        cout << "The graph does not have a cycle" << endl;

    }

    return 0;

}