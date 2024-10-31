#include <iostream>
#include <set>

using namespace std;

void ins(set<int>& s, int val) {
    s.insert(val);
}

void del(set<int>& s, int val) {
    if (s.find(val) == s.end()) {
        return;
    }
    s.erase(val);
}

bool check(set<int>& s, int val) {
    if (s.find(val) != s.end()) {
        return true;
    }
    return false;
}

int main() {
    int req;
    cin>>req;
    set<int> s;
    while (req > 0) {
        int yc;
        cin>>yc;
        if (yc == 1) {
            int val;
            cin>>val;
            ins(s, val);
        }
        else if (yc == 2) {
            int val;
            cin>>val;
            del(s, val);
        }
        else if (yc == 3) {
            int val;
            cin>>val;
            if (check(s, val)) {
                cout<<"Yes\n";
            }
            else {
                cout<<"No\n";
            }
        }
        req--;
    }
}



