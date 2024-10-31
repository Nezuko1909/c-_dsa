#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            s+=a[i];
        }
    }
    printf("S = %d", s);
    return 0;
}