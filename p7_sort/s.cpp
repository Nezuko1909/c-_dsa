#include <iostream>
#include <vector>

using namespace std;

int pt(vector<int>& a, int l, int h) {
    int p = a[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (a[j] < p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int h) {
    if (l < h) {
        int ptt = pt(a, l, h);

        quickSort(a, l, ptt - 1);
        quickSort(a, ptt + 1, h);
    }
}

void selectionSort(int n, int a[]) {
    cout<<"\nSelection Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        int minI = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minI]) {
                minI = j;
            }
        }

        swap(a[i], a[minI]);
        
        for (int i = 0; i < n; i++) {
            cout<<a[i]<<" ";
        }
        cout << endl;
    }

}

void insertSort(int n, int a[]) {
    cout<<"\nInsert Sort:\n";
    for (int i = 1; i < n; i++) {
        int k = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = k;
        
        for (int i = 0; i < n; i++) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int a1[n];
    int a2[n];
    vector<int> a3 = {};

    for (int i = 0; i < n; i++) {
        a1[i] = a[i];
        a2[i] = a[i];
        a3.push_back(a[i]);
    }

    insertSort(n, a1);
    selectionSort(n, a2);

    cout<<"\nQuickSort:\n";
    quickSort(a3, 0, a3.size() - 1);
    for (auto x : a3) {
        cout<<x<<" ";
    }
    
    return 0;
}