#include <iostream>

using namespace std;

int solve() {
    int n;
    cin>>n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sl = 0;
    int sr = 0;
    for (int i = 0; i < n; i++) sr+=a[i];
    if (sl == sr) {
        cout<<"YES\n";
        return 0;
    }
    bool check = sl < sr, check_pos = false;
    int i = 0;
    if (check) {
        do {
            if (sl == sr) {
                check_pos = true;
                break;
            }
            else {
                i++;
                sl+=a[i];
                sr-=a[i];
            }
        } while (sl < sr);
    }
    else {
        do {
            if (sl == sr) {
                check_pos = true;
                break;
            }
            else {
                i++;
                sl+=a[i];
                sr-=a[i];
            }
        } while (sl > sr);
    }
    if (check_pos) {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
    return 0;
}

int solve2() {
    int n;
    cin>>n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 1) {
        cout<<"YES\n";
        return 0;
    }
    if (n == 2) {
        if (a[1] == 0 || a[0] == 0) {
            cout<<"YES";
            return 0;
        }
        cout<<"NO\n";
        return 0;
    }
    int pos = 0;
    int sl = 0;
    int sr = 0;
    for (int i = pos + 1; i < n; i++) {
        sr+=a[i];
    }
    if (sl == sr) {
        cout<<"YES\n";
        return 0;
    }
    while(pos < n) {
        if (sl == sr) {
            cout<<"YES\n";
            return 0;
        }
        else {
            pos++;
            sl+=a[pos-1];
            sr-=a[pos];
        }
    }
    cout<<"NO\n";
    return 0;
}

int main() {
    int t;
    cin>>t;
    while (t > 0) {
        solve2();
        t--;
    }
}