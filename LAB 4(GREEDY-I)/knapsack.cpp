#include<iostream>
using namespace std;

void sortprofits(int loads[],int n,int profits[]){
    int temp,temp2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(profits[j]<profits[j+1]){
                temp=loads[j];
                temp2=profits[j];
                loads[j]=loads[j+1];
                profits[j]=profits[j+1];
                profits[j+1]=temp2;
                loads[j+1]=temp;
            }
        }
    }
}

void knapsack(int loads[],int n,int cap,int profits []){
    int maxcap=cap;
    int loaded=0;
    int profit=0;
    int i=0;
    sortprofits(loads,n,profits);
    while(maxcap>0&&i<n){
        maxcap=maxcap-loads[i];
        if(maxcap>=0){
        loaded++;
        profit=profit+profits[i];
        }
        i++;
    }
    cout<<"maximum loads loaded are :"<<loaded<<endl;
    cout<<"the maximum profit obtained is :"<<profit<<endl;
}

int main(){
    int n;
    cout<<"enter the no of loads :";
    cin>>n;
    int loads[n];
    int profits[n];
    for(int i=0;i<n;i++){
        cout<<"enter load weight :";
        cin>>loads[i];
        cout<<"enter profit of this weight :";
        cin>>profits[i];
    }
    int cap;
    cout<<"enter the maximum capacity of the knapsack :";
    cin>>cap;
    knapsack(loads,n,cap,profits);
}
