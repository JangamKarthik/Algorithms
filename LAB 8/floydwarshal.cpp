#include <iostream>
using namespace std;
void printm(int a[20][20], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}
void floyd(int a[20][20], int n)
{
    int i, j, k, d;
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i!=k && j!=k)
                {
                    if(i!=j)
                    {
                        d= (a[i][k]+ a[k][j]);
                        if(a[i][k]>0 && a[k][j]>0)
                        {
                            if((d< a[i][j]) || a[i][j]==-1)
                            {
                                a[i][j]=d;
                            }
                        }
                    }
                }
            }
        }
    }
    printm(a,n);
}
int main() 
{
    int n, e, i, j, a[20][20], u, v, c;
    cout << "Enter number of vertices and edges\n";
    cin>>n>>e;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            a[i][j]=-1;
            if(i==j)
            {
                a[i][j]=0;
            }
        }
    }
    cout<<"Enter adjacent vertices\n";
    for(i=0; i<e; i++)
    {
        cin>>v>>u>>c;
        //a[u][v]=1;
        a[v][u]=c;
    }
    floyd(a,n);
    return 0;
}
