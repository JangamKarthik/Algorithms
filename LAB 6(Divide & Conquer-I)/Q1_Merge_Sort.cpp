#include <bits/stdc++.h>
using namespace std;
int c = 0;

// Function to merge two subarrays of the given array a
// First subarray is a[l..m]
// Second subarray is a[m+1..r]
void merge(int *a, int l, int m, int r) {
    // Declare variables i, j, k, nl, nr
    int i, j, k, nl, nr;
    
    // Increment step count
    c++;
    
    // Calculate size of left and right subarrays
    nl = m - l + 1;
    c++;
    nr = r - m;
    c++;
    
    // Declare left and right subarrays of size nl and nr
    int la[nl], ra[nr];
    c++;

    // Copy elements of left subarray to la[]
    for (i = 0; i < nl; i++) {
        c++;
        la[i] = a[l + i];
        c++;
    }
    c++;

    // Copy elements of right subarray to ra[]
    for (j = 0; j < nr; j++) {
        c++;
        ra[j] = a[m + 1 + j];
        c++;
    }
    c++;

    // Merge the two subarrays back into the original array a[]
    i = 0;
    c++;
    j = 0;
    c++;
    k = l;
    c++;
    while (i < nl && j < nr) {
        if (la[i] <= ra[j]) {
            c++;
            a[k] = la[i];
            c++;
            i++;
            c++;
        } else {
            c++;
            a[k] = ra[j];
            c++;
            j++;
            c++;
        }
        k++;
        c++;
    }
    c++;

    // Copy remaining elements of left subarray to a[]
    while (i < nl) {
        c++;
        a[k] = la[i];
        c++;
        i++;
        k++;
        c++;
        c++;
    }
    c++;

    // Copy remaining elements of right subarray to a[]
    while (j < nr) {
        c++;
        a[k] = ra[j];
        c++;
        j++;
        k++;
        c++;
        c++;
    }
    c++;
}

// Function to perform merge sort on the given array a
// l is the starting index of the subarray to be sorted
// r is the ending index of the subarray to be sorted
void mergeSort(int *a, int l, int r) {
    int m;
    
    // Increment step count
    c++;
    
    // Check if there are at least two elements to be sorted
    if (l < r) {
        // Calculate the middle index of the subarray
        m = l + (r - l) / 2;
        c++;
        
        // Sort the left and right subarrays recursively
        mergeSort(a, l, m);
        c++;
        mergeSort(a, m + 1, r);
        c++;
        
        // Merge the sorted subarrays
        merge(a, l, m, r);
        c++;
    }
}

int main() {
    int n;
    c++;
    cout << "Enter number of elements: ";
    c++;
    cin >> n;
    c++;
    int a[n];
    c++;

    cout << "Enter elements:";
    c++;
    for (int i = 0; i < n; i++) {
        c++;
        cin >> a[i];
        c++;
    }

    mergeSort(a, 0, n - 1);
    c++;
    cout << "Sorted Array: ";
    c++;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n\nStep count : " << c << endl;
    return 0;
}
