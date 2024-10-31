#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        a.push_back(d);
    }
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        b.push_back(d);
    }

    int mx = 0;
    int d = 0;

    while (mx <= x) {
        if (a[0] < b[0] && !a.empty()) {
            mx+=a[0];
            d++;
            a.erase(a.begin());
        } else if (b[0] < a[0] && !b.empty()) {
            mx+=b[0];
            d++;
            b.erase(b.begin());
        }

        if (!a.empty() && b.empty()) {
            mx+=a[0];
            d++;
            a.erase(a.begin());
        }

        if (a.empty() && !b.empty()) {
            mx+=b[0];
            d++;
            b.erase(b.begin());
        }
    }
    cout<<d;
    return 0;
}




