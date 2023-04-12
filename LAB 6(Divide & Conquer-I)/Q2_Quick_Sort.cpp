#include<iostream>
using namespace std;

void print(int arr[],int n){
    cout<<"the sorted array is :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int partition(int arr[],int l,int r){
    int p=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(arr[j]<p){
            i++;
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
   int tem;
   tem=arr[i+1];
   arr[i+1]=arr[r];
   arr[r]=tem;
    return i+1;
}

void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main(){
    cout<<"enter the no of elements in the array :";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter an element :";
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    print(arr,n);
    return 0;
}
