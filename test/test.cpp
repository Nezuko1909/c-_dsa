#include <iostream>

using namespace std;

void selectionSort(int n, int a[]) {
    for (int i = n - 1; i > 0; i--) {
        int maxI = i;

        for (int j = 0; j < i; j++) {
            if (a[j] > a[maxI]) {
                maxI = j;
            }
        }

        if (maxI != i) {
            swap(a[i], a[maxI]);
            cout << maxI << " ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        selectionSort(N, a);
    }
    return 0;
}
