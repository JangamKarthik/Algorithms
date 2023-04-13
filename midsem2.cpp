#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

const int MAX=100;
int graph[MAX][MAX];
int graph1[MAX][MAX];
int graph2[MAX][MAX];
int vis[MAX],dist[MAX];
int vis1[MAX],dist1[MAX];
int vis2[MAX],dist2[MAX];
int val1=0;
int val2=0;
int v,e;

int minidx(int vis[],int dist[])
{
    int mindis=INT_MAX;
    int idx;
    for(int i=0; i<v; i++)
    {
        if(vis[i]==0 && dist[i]<=mindis)
        {
            mindis=dist[i];
            idx=i;
        }
    }
    return idx;
}

void dj1(int src)
{
    for(int i=0; i<v; i++)
    {
        dist[i]=INT_MAX;
        vis[i]=0;
    }
    dist[src]=0;
    for(int k=0; k<v; k++)
    {
        int m=minidx(vis,dist);
        vis[m]=1;
        for(int i=0; i<v; i++)
        {
            if(vis[i]==0 && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<=dist[i])
            {
                dist[i]=dist[m]+graph[m][i];
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        cout<<"shortest distance of "<<i<<" "<<dist[i]<<endl;
    }

}

void dj2(int src)
{
    for(int i=0; i<v; i++)
    {
        dist1[i]=INT_MAX;
        vis1[i]=0;
    }
    dist1[src]=0;
    for(int k=0; k<v; k++)
    {
        int m=minidx(vis1,dist1);
        vis[m]=1;
        for(int i=0; i<v; i++)
        {
            if(vis1[i]==0 && graph1[m][i] && dist1[m]!=INT_MAX && dist1[m]+graph1[m][i]<=dist1[i])
            {
                dist1[i]=dist1[m]+graph1[m][i];
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        cout<<"shortest distance of "<<i<<" "<<dist1[i]<<endl;
        val1=val1+dist1[i];
    }

}

void dj3(int src)
{
    for(int i=0; i<v; i++)
    {
        dist2[i]=INT_MAX;
        vis2[i]=0;
    }
    dist2[src]=0;
    for(int k=0; k<v; k++)
    {
        int m=minidx(vis2,dist2);
        vis2[m]=1;
        for(int i=0; i<v; i++)
        {
            if(vis2[i]==0 && graph2[m][i] && dist2[m]!=INT_MAX && dist2[m]+graph2[m][i]<=dist2[i])
            {
                dist2[i]=dist2[m]+graph2[m][i];
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        cout<<"shortest distance of "<<i<<" "<<dist2[i]<<endl;
        val2=val2+dist2[i];
    }

}

int main()
{
    cout<<"enter the no of vertices :";
    cin>>v;

    cout<<"enter the no of edges :";
    cin>>e;


//memset(vis,0,sizeof(vis));
//memset(dist,INT_MAX,sizeof(dist));

    for(int i=0; i<e; i++)
    {
        int src,dst,w;
        cout<<"enter a source and destination of an edge :";
        cin>>src>>dst;
        cout<<"enter the weight of your edge :";
        cin>>w;
        graph[src][dst]=w;
        graph1[src][dst]=w;
        graph2[src][dst]=w;
        graph[dst][src]=w;
        graph1[dst][src]=w;
        graph2[dst][src]=w;
    }
    cout<<"enter a source for traversing :";
    int src;
    cin>>src;
    dj1(src);
    cout<<"enter two new cities to travel :";
    int src1,src2;
    cin>>src1>>src2;

    dj2(src1);
    dj3(src2);
    cout<<"the total value of distances from city 1 :"<<val1<<endl;
    cout<<"the total value of distances from city 2 :"<<val2<<endl;
    if(val1<val2)
    {
        cout<<"city "<<src1<<" is better for relocating"<<endl;
    }

    else
    {
        cout<<"city "<<src2<<" is better for relocating"<<endl;
    }

    return 0;
}
