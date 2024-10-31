#include <iostream>
#include <map>

using namespace std;

void add(map<string, int>& m, string name, int val) {
    if (m.find(name) != m.end()) {
        m[name] += val;
    } else {
        m[name] = val;
    }
}

void del(map<string, int>& m, string name) {
    if (m.empty()) {
        cout<<"0\n";
        return;
    }
    if (m.find(name) != m.end()) {
        m[name] = 0;
        return;
    }
}

void print(map<string, int>& m, string name) {
    if (m.empty()) {
        return;
    }
    if (m.find(name) != m.end()) {
        cout<<m[name]<<"\n";
    }
    else {
        cout<<"0\n";
    }
}

int main() {
    int q;
    cin>>q;
    map<string, int> list;
    while (q > 0) {
        int type;
        cin>>type;
        if (type == 1) {
            string name;
            int val;
            cin>>name;
            cin>>val;
            add(list, name, val);
        } else if (type == 2) {
            string name;
            cin>>name;
            del(list, name);
        } else if (type == 3) {
            string name;
            cin>>name;
            print(list, name);
        }
        q--;
    }

}