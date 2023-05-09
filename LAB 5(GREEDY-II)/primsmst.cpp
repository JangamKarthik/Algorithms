#include<iostream>
using namespace std;
int v,e;
int minkey(int visited[],int key[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0 && key[i]<min)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void print(int parent[],int graph[v][v])
{
    int total=0;
    cout<<"Edges    weight"<<endl;
    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<"--"<<i<<"   "<<graph[i][parent[i]]<<endl;
        total=total+graph[i][parent[i]];
    }
    cout<<"Total Weight="<<total;
}
void prim(int graph[v][v])
{
    int visited[v],key[v],parent[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<v-1;i++)
    {
        int u=minkey(visited,key);
        visited[u]=1;
        for(int j=0;j<v;j++)
        {
            if(graph[u][j] && graph[u][j]<key[j] && visited[j]==0)
            {
                key[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
    print(parent,graph);
}
int main()
{
    cout<<"enter the no of vertices: ";
    cin>>v;

    cout<<"enter the no of edges: ";
    cin>>e;

    int graph[v][v];

    for(int i=0;i<e;i++){
        int u,v,w;

        cout<<"enter the source and destination of the edge: ";
        cin>>u>>v;

        cout<<"enter the weight of the edge: ";
        cin>>w;

        graph[u][v]=w;
    }
    

    prim(graph);

}
