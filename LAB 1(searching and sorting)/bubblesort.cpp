#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &count) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        count++;
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            // Increment the count variable
            count++;

            // Swap adjacent elements if they are in the wrong order
            count++;
            if (arr[j] > arr[j + 1])
            {
                int temp;
                count++;
               temp=arr[j];
               count++;
               arr[j]=arr[j+1];
               count++;
               arr[j+1]=temp;
               count++;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: "<<endl;
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;
    bubbleSort(arr, n, count);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << "Stepcount is: " << count << endl;

    return 0;
}
