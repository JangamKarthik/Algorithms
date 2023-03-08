#include <iostream>
#include <stack>
using namespace std;
const int MAX=100;
bool vis[MAX];
stack<int> s;
#include <array>

void dfs(int x,int arr[MAX][MAX],bool vis[MAX],int e,int v,int c,int a[MAX]){
    s.push(x);
    vis[x]=true;
    int f=0;
    
    while(!s.empty()){
        int curr=s.top();
        a[f]=s.top();
         s.pop();

        for(int i=0 ; i<v; i++){
            if(arr[curr][i]==1 && !vis[i]){
                s.push(i);
                vis[i]=true;
                c++;
            }
        }
        f++;
    }
}

int main(){

    int arr[MAX][MAX];
    int v,e;
    
    cout<<"enter e :";
    cin>>e;

    cout<<"enter v :";
    cin>>v;

    for(int i=0; i < v ;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int s=0,d=0;
        cout<<"enter s d :";
        cin>>s >>d;

        arr[s][d]=1;

    }

    /*int x;
    cout<<"enter start node :";
    cin>>x;*/
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl; 
    
    for(int i=0;i<v;i++){
        int count=1;
        int a[MAX];
        for(int i=0;i<100;i++){
            a[i]=0;
        }
        dfs(i,arr,vis,e,v,count,a);
        int s = sizeof(a) / sizeof(a[0]);
        if(count>3){
            for(int i=0;i<s;i++){
                cout<<a[i]<<" ";
            }
        }
    }
}