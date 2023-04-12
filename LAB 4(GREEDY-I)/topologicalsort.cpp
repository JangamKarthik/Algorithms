#include<iostream>
#include<stack>
using namespace std;

const int MAX=100;
int v,e;

void topological(int arr[MAX][MAX],int vis[],int start){
    stack <int> s;
    stack <int> s2;
    s.push(start);
    vis[start]=1;
    while(!s.empty()){
        int curr=s.top();
        s2.push(curr);
        s.pop();
        for(int i=0;i<v;i++){
            if(arr[curr][i] && vis[i]==0){
                s.push(i);
                vis[i]=1;
            }
        }
    }
    int topo[MAX];
    int j=0;
    while(!s2.empty()){
        topo[j++]=s2.top();
        s2.pop();
    }

    cout<<"the topological order is :";
    for(int i=j-1;i>=0;i--){
        cout<<" "<<topo[i];
    }
}

int main(){
    cout<<"enter the no of vertices :";
    cin>>v;
    cout<<"enter the no of edges :";
    cin>>e;
    int arr[MAX][MAX] = {0};
    for(int i=0;i<e;i++){
        int src,dst;
        cout<<"enter the source and desitation for the edge :";
        cin>>src>>dst;
        arr[src][dst]=1;
    }
    int vis[v] = {0};

    int start;
    cout<<"enter the starting vertex for traversing:";
    cin>>start;

    topological(arr,vis,start);
    return 0;
}
