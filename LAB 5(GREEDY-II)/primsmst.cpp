#include <iostream>
using namespace std;

int V,E;

bool isValidEdge(int u, int v, bool inMST[]) {
    if (u == v) return false;
    if (inMST[u] == 0 && inMST[v] == 0) return false;
    else if (inMST[u] == 1 && inMST[v] == 1) return false;
    return true;
}

void primsMST(int graph[10][10]) {
    bool inMST[V+1] = {0};
    inMST[0] = 1;
    int edge_count = 0, mincost = 0;
    while (edge_count < V-1) {
        int min = INT_MAX, a=-1, b=-1;
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (graph[i][j] < min) {
                        if (isValidEdge(i,j,inMST)) {
                            min = graph[i][j];
                            a = i;
                            b = j;
                        }
                }
            }
        }
        if (a != -1 && b != -1) {
            cout<< "Edge " << edge_count++ << " : ("<<a<<" "<<b<<") "<< "Cost: " << min <<endl;
            mincost = mincost + min;
            inMST[b] = inMST[a] = 1;
        }
    }
    cout<< "Minimum cost: " << mincost;
}

int main() {

    cout<< "Enter number of nodes and vertices: ";
    cin>> V >> E;
    int graph[10][10];
    for (int i=0; i<=V; i++){
        for (int j=0; j<=V; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    cout<< "Enter source, destination, cost respectively: "<<endl;
    for (int i=0; i<E; i++) {
        int p,q,cost;
        cin>> p >> q >> cost;
        graph[p][q] = graph[q][p] = cost;
    }

    primsMST(graph);

    return 0;
}

/*
5 7
0 1 2
1 2 3
0 3 6
3 1 8
1 4 5
3 4 9
1 4 5
*/
