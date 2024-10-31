#include <iostream>

using namespace std;

int main(){
    int m, n;
    cin>>m>>n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    int d = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int t = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
            if ( t == 0) d++;
        }
    }
    cout << d;
    return 0;
}