#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        s+=a[i];
    }
    s/=n;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > s) d++;
    }
    cout<<d;
    return 0;
}