#include <iostream>
using namespace std;

const int MAX = 1000;

int graph[MAX][MAX]; // adjacency matrix to represent the graph
int transpose[MAX][MAX]; // adjacency matrix to represent the transpose of the graph

int main() {
    int n, m; // n is the number of vertices, m is the number of edges
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;
    cout << "Enter the edges of the graph: " << endl;

    // Read in the edges of the graph
    for (int i = 0; i < m; i++) {
        int u, v; // u and v are the endpoints of an edge
        cin >> u >> v;
        graph[u][v] = 1; // set the corresponding entry in the adjacency matrix to 1
    }

    // Compute the transpose of the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[j][i] = graph[i][j]; // swap the indices to get the transpose
        }
    }

    // Print the transpose of the graph
    cout << "The transpose of the graph is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
