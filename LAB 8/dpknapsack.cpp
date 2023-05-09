#include<iostream>
using namespace std;
int main()
{
    int n,c;
    cout<<"Enter no of items"<<endl;
    cin>>n;
    int p[n+1],wt[n+1];
    cout<<"Enter the capacity"<<endl;
    cin>>c;
    int v[n+1][c+1];
    cout<<"Enter profit and weight of each item"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<"item"<<i<<endl;
        cin>>p[i];
        cin>>wt[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=c;w++)
        {
            if(i==0||w==0)
            {
                v[i][w]=0;
            }
            else if(wt[i]<=w)
            {
                v[i][w]=max(p[i]+v[i-1][w-wt[i]],v[i-1][w]);
            }
            else 
            v[i][w]=v[i-1][w];
        }
    }
    int i,j;
    i=n;
    j=c;
    while(i>=0 && j>=0)
    {
        if(v[i][j]==v[i-1][j])
        {
            cout<<i<<"=0"<<endl;
            i--;
        }
        else
        {
            cout<<i<<"=1"<<endl;
            j=j-wt[i];
            i--;
        } 
        

    }
    return 0;
}
