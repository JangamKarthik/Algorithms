#include<iostream>
using namespace std;
#define v 5
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
    
    int graph[v][v] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    prim(graph);

}
