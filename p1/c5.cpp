#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        a[i] % 2 == 0 ? c++ : l++;
    }
    cout<<c<<" "<<l;
    return 0;
}