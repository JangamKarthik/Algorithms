#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x, int &count) {
    // Base case: If left index is greater than right index
    count++;
    if (left > right)
    {   
        count++;
        return -1;
    }

    // Calculate mid index
    int mid = left + (right - left) / 2;

    // Increment the count variable
    count++;
    count++;
    // If the element is present at the middle
    if (arr[mid] == x)
    {   
        count++;
        return mid;
    }

    count++;
    // If element is smaller than mid, search in the left half
    if (arr[mid] > x)
    {   
        count++;
        return binarySearch(arr, left, mid - 1, x, count);
    }

    // If element is greater than mid, search in the right half
    else
    {
        count++;
        return binarySearch(arr, mid + 1, right, x, count);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: "<<endl;
    cin >> n;

    int arr[n];

    // Input the array elements in sorted order
    cout << "Enter the elements of the array in sorted order: "<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Search for an element
    int x;
    cout << "Enter the element to be searched: "<<endl;
    cin >> x;

    int count = 0;
    int result = binarySearch(arr, 0, n - 1, x, count);

    if (result == -1)
        cout << "Element is not present in the array";
    else
        cout << "Element is present at index " << result;

    cout << endl << "Stepcount is: " << count << endl;

    return 0;
}
