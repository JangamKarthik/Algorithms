#include <iostream>
using namespace std;

int count = 0;

// function to perform selection sort on an array of integers
void selectionSort(int arr[], int n) {
    // variable to count the number of steps taken by the algorithm
    

    // loop through the array, selecting the minimum element in each iteration
    for (int i = 0; i < n - 1; i++) {
    count++;

        // set minIndex as the index of the current minimum element
        int minIndex = i;
        count++;

        // loop through the remaining unsorted portion of the array to find the minimum element
        for (int j = i + 1; j < n; j++) {
            count++;
            count++;

            // if the current element is less than the current minimum, update minIndex
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                count++;
            }
        }

        // swap the minimum element with the first element in the unsorted portion of the array
        int temp = arr[i];
        count++;
        arr[i] = arr[minIndex];
        count++;
        arr[minIndex] = temp;
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

    // call the selectionSort function to sort the array and calculate its time complexity
    selectionSort(arr, n);

    return 0;
}
