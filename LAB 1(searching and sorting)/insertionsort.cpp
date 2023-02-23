#include <iostream>
using namespace std;

int count = 0;

// function to perform insertion sort on an array of integers
void insertionSort(int arr[], int n) {
    // variable to count the number of steps taken by the algorithm

    // loop through the array, starting from the second element
    for (int i = 1; i < n; i++) {
        count++;
        
        // set key as the current element to be inserted into the sorted portion of the array
        int key = arr[i];
        
        count++;

        // set j as the index of the element immediately before key
        int j = i - 1;
        count++;

        // find the correct position of key within the sorted portion of the array
        while (j >= 0 && arr[j] > key) {
            count++;

            // move the element at arr[j] one position to the right
            arr[j + 1] = arr[j];
            count++;

            // decrement j
            j--;
            count++;

        }

        // insert key into the sorted portion of the array at index j+1
        arr[j + 1] = key;
        // increment the step count
        count++;
    }

    // print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // print the total number of steps taken by the algorithm
    cout << "Total number of steps: " << count << endl;
}

// main function
int main() {
    // prompt the user to enter the number of elements to be sorted
    int n;
    cout << "Enter the number of elements to be sorted: "<<endl;
    cin >> n;

    // allocate an array of size n to hold the input
    int arr[n];

    // prompt the user to enter n integers and read them into the array
    cout << "Enter " << n << " integers to be sorted: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // call the insertionSort function to sort the array and calculate its time complexity
    insertionSort(arr, n);

    return 0;
}
