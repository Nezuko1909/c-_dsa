#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream file_in("b_test.txt");
    ofstream file_out("ans.txt");
    int n;
    file_in>>n;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        file_in>>a[i];
    }

    int closest = a[0] - a[1] >= 0 ? a[0] - a[1] : a[1] - a[0];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] - a[j] >= 0) {
                if (closest >= a[i] - a[j]) {
                    closest = a[i] - a[j];
                }
            }
            else {
                if (closest >= a[j] - a[i]) {
                    closest = a[j] - a[i];
                }
            }
        }
    }

    vector<int> ans;
    ans.resize(0);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] - a[j] >= 0) {
                if (closest == a[i] - a[j]) {
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                }
            }
            else {
                if (closest == a[j] - a[i]) {
                    ans.push_back(a[j]);
                    ans.push_back(a[i]);
                }
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) file_out<<ans[i]<<" ";
    return 0;
} 