#include <iostream>

using namespace std;

// Define a constant for the maximum number of vertices
const int MAXN = 100;

// Define a global adjacency matrix to represent the graph
int adj_mat[MAXN][MAXN];

// Define a global boolean array to keep track of visited vertices
bool visited[MAXN];

// Define a function to perform a depth-first search of the graph
void dfs(int u, int depth, int path[], int path_len) {
    // Mark the current vertex as visited and add it to the current path
    visited[u] = true;
    path[path_len++] = u;
    
    // If the current path has length greater than 3, print it out
    if (depth > 3) {
        cout << "Path greater than 3 found: ";
        for (int i = 0; i < path_len; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    
    // Recursively visit all unvisited neighbors of the current vertex
    for (int v = 0; v < MAXN; v++) {
        if (adj_mat[u][v] && !visited[v]) {
            dfs(v, depth + 1, path, path_len);
        }
    }
    
    // Unmark the current vertex and remove it from the current path
    visited[u] = false;
}

int main() {
    // Ask the user for the number of vertices and edges in the graph
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    // Initialize the adjacency matrix to all zeroes (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_mat[i][j] = 0;
        }
    }
    
    // Read in the edges from the user and add them to the adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter the source and destination vertices for edge " << i+1 << ": ";
        cin >> u >> v;
        adj_mat[u][v] = 1;
        //adj_mat[v][u] = 1;
    }
    
    // Initialize the array to keep track of the current path
    int path[MAXN];
    int path_len = 0;
    
    // Traverse the graph using depth-first search
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(u, 1, path, path_len);
        }
    }
    
    return 0;
}
