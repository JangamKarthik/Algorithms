#include <iostream>

using namespace std;

const int MAX_N = 100; // Maximum number of loads
const int MAX_C = 1000; // Maximum capacity of the container

int main() {
    int n; // Number of loads
    int c; // Capacity of the container
    int w[MAX_N]; // Array of load weights
    int used = 0; // Amount of container capacity used
    int cnt = 0; // Number of loads packed

    // Read input values
    cout << "Enter number of loads: ";
    cin >> n;
    cout << "Enter capacity of container: ";
    cin >> c;
    cout << "Enter weights of loads:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // Sort loads in decreasing order of weight using bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (w[j] > w[j+1]) {
                swap(w[j], w[j+1]);
            }
        }
    }

    // Pack loads into container using first-fit decreasing algorithm
    for (int i = 0; i < n; i++) {
        if (used + w[i] <= c) {
            used += w[i];
            cnt++;
        } else {
            break;
        }
    }

    // Print output values
    cout << "Number of loads packed: " << cnt << endl;
    cout << "Amount of container capacity used: " << used << endl;

    return 0;
}
