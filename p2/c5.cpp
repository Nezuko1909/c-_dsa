#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int d = 0;

    sort(a, a + n);

    int i = 1, j = 0;
    while(1) {
        if (a[i] - a[j] > k) {
            j + 1 < i ? j++ : i++;
            if (i == n) break;
        }
        if (a[i] - a[j] < k) {  
            i++;
            if (i == n) break;
        }
        if (a[i] - a[j] == k) {
            d++;
            j + 1 < i ? j++ : i++;
            if (i == n) break;
        }
    }
    cout<<d;
    return 0;
}

/*
int main() {
    int n, k;
    cin>>n>>k;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int d = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] - a[j] >= 0) {
                if (k == a[i] - a[j]) {
                    d++;
                }
            }
            else {
                if (k == a[j] - a[i]) {
                    d++;
                }
            }
        }
    }

    cout<<d;
    return 0;
} 
*/