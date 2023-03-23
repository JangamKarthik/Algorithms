#include <iostream>
using namespace std;

void sortKP(int p[], int w[], int n,int d[]) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1;i++) {
            if(p[j] < p[j+1]) {
                swap(p[j], p[j+1]);
                swap(w[j], w[j+1]);
                swap(d[j], d[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int profit[n];
    int weight[n];
    int density[n];
    for(int i =0; i<n; i++) {
        cin >> profit[i];
        cin >> weight[i];
        density[i]=profit[i]/weight[i];
    }
    int c,capacity;
    cin >> c;
    capacity =c;
    sortKP(profit, weight, n, density);
    int i=0;
    int maxpd=0;
    while(capacity > 0) {
        if(capacity - weight[i] < 0) break;
        capacity = capacity - weight[i];
        maxpd += profit[i];
        i++;
    }
    cout << maxpd;
}

