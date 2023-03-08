#include<iostream>
using namespace std;
#include<queue>
const int MAX = 100;

void bfs(int arr[MAX][MAX],int n,bool a[],int v,int e)
{
    queue<int> q;

    a[n]={true};

    q.push(n);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";

        for(int i=0;i<v;i++){
            if(arr[curr][i]==1 && !a[i]){
                a[i]=true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int v,e;
    int mat[MAX][MAX] = {0};
    cout<<"enter v"<<endl;
    cin>>v;
    cout<<"enter e"<<endl;
    cin>>e;
    for(int i=0;i<e;i++){
        int s,d;
        cout<<"Enter the source and destination of edge "<<i<<" :";
        cin >> s >> d;
        mat[s][d]=1;
    }
    
    bool vis[MAX] = {false};

    int startv;

    cout<<"Enter start vertex :";
    cin>>startv;

    bfs(mat,startv,vis,v,e);
}