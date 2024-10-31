#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> dq;
    int mx = arr[0];
    int found_pos = 0;
    for (int i = 0; i < k; i++) {
        if (mx < arr[i]) {
            mx = arr[i];
            found_pos = i;
        }
    }
    dq.push_back(mx);

    int l = 1;
    int r = k;
    while (r < n) {
        if (l <= found_pos) {
            if (arr[r] < mx) {
                dq.push_back(mx);
            } else {
                mx = arr[r];
                found_pos = r;
                dq.push_back(mx);
            }
        } else {
            mx = arr[l];
            for (int i = l; i <= r; i++) {
                if (mx < arr[i]) {
                    mx = arr[i];
                    found_pos = i;
                }
            }
            dq.push_back(mx);
        }
        l++;
        r++;
    }

    for (auto x : dq) {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}

