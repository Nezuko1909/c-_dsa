#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin>>m>>n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    int s[n]; 
    for (int i = 0; i < n; i++) {
        s[i] = 0;
        for (int j = 0; j < m; j++) {
            s[i]+=a[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<s[i]<<" ";
    }
    return 0;
}


