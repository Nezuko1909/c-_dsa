#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int closest = a[0] - a[1] >= 0 ? a[0] - a[1] : a[1] - a[0];

    sort(a, a + n);

    for (int i = 1; i < n; i++) {
        if (closest >= a[i] - a[i-1]) {
            closest = a[i] - a[i-1];
        }
    }

    for (int i = 1; i < n; i++) {
        if (closest == a[i] - a[i-1]) {
            cout<<a[i-1]<<" "<<a[i]<<" ";
        }
    }

    return 0;
} 