#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

const int CITIES = 10;

int graph[CITIES][CITIES];
int mincost = INT_MAX;
int vis[CITIES];

void tsp(int src,int nc,int currcost,int nv){

    if(nv==nc){
        mincost=min(currcost,mincost);
        return;
    }

    for(int i=0;i<nc;i++){
        if(graph[src][i]!=0 && vis[i]==0){
            vis[i]=1;
            tsp(i,nc,currcost+graph[src][i],nv+1);
Vis[i]=0;
        }
    }
}

int main(){
    int nc;
    cout<<"enter the no of cities: ";
    cin>>nc;
    cout<<"enter the adjacency matrix: "<<endl;
    for(int i=0;i<nc;i++){
        for(int j=0;j<nc;j++){
            cin>>graph[i][j];
        }
    }
    memset(vis,0,sizeof(vis));
    int src;
    cout<<"enter the source for traversing: ";
    cin>>src;
    vis[src]=1;
    tsp(src,nc,0,1);
  

    cout<<"minimum cost: "<<mincost<<endl;

    return 0;
}
tsp using bt
