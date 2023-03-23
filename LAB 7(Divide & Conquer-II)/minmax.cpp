#include <iostream>
#include <utility>
using namespace std;

//function to find the min and max
pair<int,int> minmax(int arr[],int low,int high)
{
    //here i am using recursion for my base case ill take if array has one element only
    if(low==high){
        return make_pair(arr[low],arr[high]);
    }

    //if array has more than one element
    if(high == low+1)
    {
        if(arr[low]<arr[high])
        {
            return make_pair(arr[low],arr[high]);
        }
        else
        {
            return make_pair(arr[high],arr[low]);
        }
    }

    //dividing the array into two parts and finding the min and max element in each part recursively
    int mid = (low+high)/2;
    pair<int,int> leftminmax = minmax(arr,low,mid);
    pair<int,int> rightminmax = minmax(arr,mid+1,high);

    //combining the results from two parts
    int minval = min(leftminmax.first,rightminmax.first);
    int maxval = max(leftminmax.second,rightminmax.second);
    return make_pair(minval,maxval);
}

int main(){
    int n;
    cout<<"kitne elements hai bhai array mei :";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"enter an element :";
        cin>>arr[i];
    }

    pair<int,int> highlow = minmax(arr, 0 , n-1);

    cout<<"minmimum value is :"<<highlow.first<<endl;
    cout<<"maximum value is :"<<highlow.second<<endl;

    return 0;
}
