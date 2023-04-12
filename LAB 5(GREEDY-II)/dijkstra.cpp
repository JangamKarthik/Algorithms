#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

const int MAX=100;
int numVertices,numEdges;
int adjMatrix[MAX][MAX];
int miniDist(int distance[], bool Tset[])
{
    int minimum=INT_MAX,ind;

    for(int k=0;k<numVertices;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[MAX][MAX],int src)
{
    int distance[numVertices];
    bool Tset[numVertices];


    for(int k = 0; k<numVertices; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0;

    for(int k = 0; k<numVertices; k++)
    {
        int m=miniDist(distance,Tset);
        Tset[m]=true;
        for(int k = 0; k<numVertices; k++)
        {

            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<numVertices; k++)
    {
        char str=65+k;
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{       
        cout<<"enter the no of vertices"<<endl;

    cin >> numVertices;

    cout<<"enter no of edges"<<endl;

    cin>> numEdges;

    memset(adjMatrix, 0, sizeof(adjMatrix));

    for (int i = 0; i < numEdges; i++) {

        int u, v, w;

        cout<<"enter source and destination of the edge"<<endl;

        cin >> u >> v;

        cout<<"enter the weight of this edge :";
        cin>>w;
        
        // Add edge to adjacency matrix
        adjMatrix[u][v] = w;

    }
        cout<<"enter a source vertex for traversing :";
        int src;
        cin>>src;

    DijkstraAlgo(adjMatrix,src);
    
    return 0;
}
