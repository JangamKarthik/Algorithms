// Include input/output stream library
#include<iostream>

// Use the standard namespace
using namespace std;

// Define a constant MAX to represent the maximum number of vertices in the graph
const int MAX = 1000;

// Define a 2D array graph to represent the graph
int graph[MAX][MAX];

// Define a boolean array visited to keep track of which vertices have been visited during the depth first search traversal
bool visited[MAX];

// Function to do depth first search traversal
void dfs(int v, int n) {

    // Mark the vertex v as visited
    visited[v] = true;

    // Iterate over all vertices in the graph
    for (int i = 0; i < n; i++) {

        // If there is an edge from v to i and i has not been visited
        if (graph[v][i]==1 && !visited[i])

            // Recursively call dfs on i
            dfs(i, n);

    }
}

// Function to find the mother vertices
void findMother(int n) {

    // Create an array to store the mother vertices
    int mothers[MAX];
    int num_mothers = 0;

    // Traverse the graph and find the last vertex visited in DFS
    // Iterate over all vertices in the graph
    for (int i = 0; i < n; i++) {

        // If i has not been visited
        if (!visited[i]) {

            // Call dfs on i
            dfs(i, n);

            // Check if the last vertex visited is a mother vertex
            bool isMother = true;

            // Reset the visited array
            fill_n(visited, n, false);

            // Call dfs on the last vertex visited
            dfs(i, n);

            // Iterate over all vertices in the graph
            for (int j = 0; j < n; j++) {

                // If j has not been visited
                if (!visited[j]) {

                    // i is not a mother vertex
                    isMother = false;
                    break;
                }
            }

            // If i is a mother vertex
            if (isMother) {
                mothers[num_mothers] = i;
                num_mothers++;
            }

            // Reset the visited array
            fill_n(visited, n, false);
        }
    }

    // Print the mother vertices
    if (num_mothers == 0) {
        cout << "There are no mother vertices in the graph" << endl;
    }
    else {
        cout << "The mother vertices of the graph are: ";
        for (int i = 0; i < num_mothers; i++) {
            cout << mothers[i] << " ";
        }
        cout << endl;
    }
}

int main(void) {

    // Declare variables to store the number of vertices, number of edges, and the endpoints of each edge
    int n, m, u, v;

    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    cout << "Enter the edges of the graph: " << endl;

    // Iterate over the number of edges
    for (int i = 0; i < m; i++) {

        // Read in the endpoints of the edge
        cin >> u >> v;

        // Set the corresponding entry in the adjacency matrix to 1
        graph[u][v] = 1;
    }

    // Call the findMother function to find the mother vertices
    findMother(n);

    return
