#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);
    for (int i = 0; i < s.length() - p.size() + 1; i++) {
        string sub = s.substr(i, p.size());
        if (sub == p) {
            printf("Pattern found at index %d\n",i);
        }
    }
}