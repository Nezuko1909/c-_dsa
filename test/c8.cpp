#include <iostream>

using namespace std;

void selectionSort(int n, int a[]) {
    //cout<<"\nSelection Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        int minI = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minI]) {
                minI = j;
            }
        }

        swap(a[i], a[minI]);
        if (i != minI) cout <<i<<" "<<minI<<"\n";
    }
}

int main() {
    int t;
    cin>>t;
    while (t-- && t >= 0) {
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        cout<<"Index swap: \n";
        selectionSort(n, a);
        cout<<"\nSau khi sap xep:\n";
        for (int i = 0; i < n; i++) {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}

