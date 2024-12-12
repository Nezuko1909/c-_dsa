#include <iostream>
#include <vector>

using namespace std;

long candies(vector<int> a) {
    int n = a.size();
    vector<int> c(n, 1);

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            c[i] = c[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >=0; i--) {
        if (a[i] > a[i + 1]) {
            c[i] = max(c[i + 1] + 1, c[i]);
        }
    }

    int s = 0;
    for (auto x : c) {
        s+=x;
    }

    return s;
}

int main() {
    int n;
    cin >> n;
    vector<int> a = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout<<candies(a);
    return 0;
}

// wa katta!
