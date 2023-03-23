#include<iostream>
#include<limits.h>

using namespace std;

const int MAXN = 1000; //max number of vertices
const int INF = INT_MAX; //infinity

int n,m; //no of vertices and edges
int graph[MAXN][MAXN]; //adjacency matrix
int dist[MAXN]; //shortest distance from source to all the other vertices
int visited[MAXN]; //keeps tracks of all visited and not visited vertices
int source; //source vertex

//for initializing all the arrays defined above
void init() {
    for(int i = 0;i<MAXN;i++){
        dist[i]=INF;
        visited[i]=0;
        for(int j=0;j<MAXN;j++){
            graph[i][j]=-1;
        }
    }
}

int getmin(){
    int mindis = INF; //first initializing all the distances with infinity
    int minvertex = -1;
    for(int i=0;i<n;i++){
        if(visited[i] == 0 && dist[i]<mindis){
            mindis=dist[i]; //replacing the previous distance with new smallest distance
            minvertex=i;
        }

    }
    return minvertex;
}

void dijkstra() {
    dist[source]=0; //distance to source vertex is zero
    for(int i=0;i<n;i++){
        int u=getmin(); //get the vertex with minimum distance
        if(u == -1)
        break; //if no such vertex found break and exit
        visited[u]=1; //and mark the vertex as visited

        for(int v=0;v<n;v++){
            //loop through all the neighbours
            if(graph[u][v] == -1)
            continue; //skip non existent edges
            int weight=graph[u][v];
            if(dist[v]>dist[u]+weight){
                //update distance if shorter
                dist[v]=dist[u]+weight;
            }
        }
    }
}

int main(){
    cout<<"enter no of vertices :";
    cin>>n;

    cout<<"enter no of edges :";
    cin>>m;

    init();

    for(int i=0;i<m;i++){
        int u,v,w;
        cout<<"enter the source and destination of the edge :";
        cin>>u>>v;

        cout<<"enter the weight for the above edge :";
        cin>>w;
    }

    cout<<"enter the source for traversing :";
    cin>>source;

    dijkstra();

    for(int i=0;i<n;i++){
        cout<<"shortest distance from vertex "<<source<<" to vertex "<<i<<" is "<<dist[i]<<endl;
    }

    return 0;
}
