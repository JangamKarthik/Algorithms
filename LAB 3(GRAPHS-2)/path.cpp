#include <iostream>
using namespace std;

// Define the maximum size of the graph
#define MAX_SIZE 100

// Define a function to check if there is a path between two vertices
bool isPathExists(int graph[][MAX_SIZE], int vertices, int source, int destination, bool visited[]) {
    if (graph[source][destination] == 1) { // If there is a direct edge between the source and destination vertices
        return true;
    }

    visited[source] = true; // Mark the current vertex as visited

    for (int i = 0; i < vertices; i++) {
        if (graph[source][i] == 1 && !visited[i]) { // If there is an edge between the source and another vertex and it has not been visited
            if (isPathExists(graph, vertices, i, destination, visited)) { // Recursively check for path between the new vertex and destination
                return true;
            }
        }
    }

    return false; // If no path exists
}

int main() {
    int vertices, source, destination;
    bool visited[MAX_SIZE] = {false};

    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    int graph[MAX_SIZE][MAX_SIZE];

    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source and destination vertices: ";
    cin >> source >> destination;

    if (isPathExists(graph, vertices, source, destination, visited)) {
        cout << "There is a path between " << source << " and " << destination << endl;
    } else {
        cout << "There is no path between " << source << " and " << destination << endl;
    }

    return 0;
}
