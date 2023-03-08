#include <iostream>
using namespace std;

// Define the maximum size of the graph
#define MAX_SIZE 100

// Define a function to check if the graph is connected
void DFS(int graph[][MAX_SIZE], int vertices, int currentVertex, bool visited[], int &count) {
    visited[currentVertex] = true; // Mark the current vertex as visited
    count++; // Increment the count of visited vertices

    for (int i = 0; i < vertices; i++) {
        if (graph[currentVertex][i] == 1 && !visited[i]) { // If there is an edge between the current vertex and another vertex and it has not been visited
            DFS(graph, vertices, i, visited, count); // Recursively visit the new vertex
        }
    }
}

bool isConnected(int graph[][MAX_SIZE], int vertices) {
    bool visited[MAX_SIZE] = {false}; // Initialize all vertices as not visited
    int count = 0; // Initialize the count of visited vertices as 0

    DFS(graph, vertices, 0, visited, count); // Start DFS traversal from the first vertex

    // Check if all vertices have been visited
    if (count == vertices) {
        return true; // If count is equal to the number of vertices, the graph is connected
    } else {
        return false; // If count is less than the number of vertices, the graph is not connected
    }
}

int main() {
    int vertices;

    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    int graph[MAX_SIZE][MAX_SIZE];

    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }

    if (isConnected(graph, vertices)) {
        cout << "The graph is connected" << endl;
    } else {
        cout << "The graph is not connected" << endl;
    }

    return 0;
}
