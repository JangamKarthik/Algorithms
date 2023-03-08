#include <iostream>

#include <stack>

using namespace std;

const int MAX = 100; // Maximum number of vertices

bool visited[MAX]; // Keep track of visited vertices

int adjMatrix[MAX][MAX]; // Adjacency matrix representation of graph

void dfs(int start, int numVertices) {

    // Create a stack to hold the vertices to be visited

    stack<int> s;

    // Push the starting vertex onto the stack and mark it as visited

    s.push(start);

    visited[start] = true;

    cout<<endl<<"dfs is : ";

    while (!s.empty()) {

        // Pop the top vertex from the stack

        int curr = s.top();

        //printing the dfs

        cout<<curr<<" ";

        s.pop();

        // Visit all adjacent vertices of the current vertex

        for (int i = 0; i < numVertices; i++) {

            if (adjMatrix[curr][i] == 1 && !visited[i]) {

                // Push the adjacent vertex onto the stack and mark it as visited

                s.push(i);

                visited[i] = true;

            }

        }

    }

    cout<<endl;

}

void printAdjMatrix(int numVertices) {

    cout <<endl<< "Adjacency matrix of the graph:" << endl;

    for (int i = 0; i < numVertices; i++) {

        for (int j = 0; j < numVertices; j++) {

            cout << adjMatrix[i][j] << " ";

        }

        cout << endl;

    }

}

int main() {

    // Initialize adjacency matrix with zeros

    for (int i = 0; i < MAX; i++) {

        for (int j = 0; j < MAX; j++) {

            adjMatrix[i][j] = 0;

        }

    }

    // Read input to build the graph

    int numVertices, numEdges;

    cout<<"enter the no of vertices"<<endl;

    cin >> numVertices;

    cout<<"enter no of edges"<<endl;

    cin>> numEdges;

    for (int i = 0; i < numEdges; i++) {

        int u, v;

        cout<<"enter source and destination of the edge"<<endl;

        cin >> u >> v;

        // Add edge to adjacency matrix

        adjMatrix[u][v] = 1;

    }

    // Initialize visited array to false

    for (int i = 0; i < numVertices; i++) {

        visited[i] = false;

    }

    // Perform DFS traversal for all unvisited vertices

    for (int i = 0; i < numVertices; i++) {

        if (!visited[i]) {

            dfs(i, numVertices);

        }

    }

    // Print adjacency matrix

    printAdjMatrix(numVertices);

    return 0;

}
