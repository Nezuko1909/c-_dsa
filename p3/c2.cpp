#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        m+=a[i];
    }
    m/=n;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            d++;
        }
    }
    cout<<d;
}