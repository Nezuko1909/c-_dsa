#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j <= i; j++) {
            s+=a[j];
        }
        cout<<s<<" ";
    }
    return 0;
}