#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0, m = 1, r = 2;
    bool lmin = true, rmax = false;
    int d = 0;

    while (1) {
        if (a[l] + a[m] + a[r] < 0) {
            if (l + 1 < m) {
                if (a[l + 1] + a[m] + a[r] < 0) {
                    l++;
                }
            }
            else if (!rmax) {
                r++;
                if (r == n - 1) {
                    rmax = true;
                }
                else {
                    rmax = false;
                }
            }
            if (rmax && m + 1 == r && l + 1 == m) {
                if (a[l] + a[m] + a[r] == 0) {
                    d++;
                    break;
                }
                else {
                    break;
                }
            }
        }

        if (a[l] + a[m] + a[r] > 0) {
            if (!lmin) {
                l--;
                if (l == 0) {
                    lmin = true;
                }
                else {
                    lmin = false;
                }
            }
            else if (m - 1 > l) {
                m--;
            }
            else if (r - 1 > m) {
                r--;
            }
        }

        if (a[l] + a[m] + a[r] == 0) {
            d++;
            if (!rmax) {
                r++;
            }
            else if (m + 1 < r) {
                m++;
            }
            else if (m + 1 < r) {
                l++;
            }
            else if (rmax && m + 1 == r && m + 1 == r) {
                break;
            }
        }
    }
    cout<<d;
    return 0;
}