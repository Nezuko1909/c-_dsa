#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int x;
    cin>>x;
    x--;
    if (x >= 0 && x < n) {
        for (int i = x; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        a[n - 1] = 0;
        n--;
    }
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}

