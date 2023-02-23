#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x, int &count) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Increment the count variable
        count++;
        count++;
        // If the element is present at the middle
        if (arr[mid] == x)
        {   count++;
            return mid;
        }

        count++;
        // If element is smaller than mid, search in the left half
        if (arr[mid] > x)
        {
            count++;
            right = mid - 1;
        }

        // If element is greater than mid, search in the right half
        else
        {
            count++;
            left = mid + 1;
        }
    }

    // If element is not present in the array
    count++;
    return -1;
}

int main() {
    int n;

    cout<<"no of elements in the array"<<endl;
    
    cin>>n;

    int arr[n];

    // Initialize the array in sorted order
    for (int i = 0; i < n; i++){
        cout<<"enter an element"<<endl;
        cin>>arr[i];
    }


    // Search for an element at the beginning of the array
    int x;

    cout<<"enter the element to be searched"<<endl;
    cin>>x;

    int count = 0;
    int result = binarySearch(arr, n, x, count);

    if (result == -1)
        cout << "Element is not present in the array";
    else
        cout << "Element is present at index " << result;

    cout << endl << "stepcount is: " << count << endl;

    return 0;
}
