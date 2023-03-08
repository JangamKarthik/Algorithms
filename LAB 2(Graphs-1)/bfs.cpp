//while drawing a graph always start ur graph from 0th vertex
#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;

// Function to perform BFS of the graph
void BFS(int adjMat[MAX_SIZE][MAX_SIZE], int V, int startVertex, bool visited[]) {

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = true;
    q.push(startVertex);

    // Loop to traverse the graph using BFS
    while(!q.empty()) {

        // Dequeue a vertex from the queue and print it
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        // Traverse all the adjacent vertices of the dequeued vertex
        for(int i=0; i<V; i++) {
            if(adjMat[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {

    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    int adjMat[MAX_SIZE][MAX_SIZE] = {0}; // Initialize all elements of adjacency matrix to 0

    // Input the adjacent vertices of each vertex from the user
    for(int i=0; i<E; i++) {
        int src, dest;
        cout << "Enter the source and destination of edge " << i << ": ";
        cin >> src >> dest;
        adjMat[src][dest] = 1;
        //adjMat[dest][src] = 1; // Assuming an undirected graph
    }

    // Initialize all vertices as not visited
    bool visited[MAX_SIZE] = {false};

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    BFS(adjMat, V, startVertex, visited);
    cout<<endl;

    cout<<"the adjacency matrix is: "<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
