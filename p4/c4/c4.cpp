#include <bits/stdc++.h>

using namespace std;

// wrong
string isBalanced(string s) {
    size_t l = 0;
    size_t r = s.size() - 1;
    while (l < r) {
        if (s[l] == '(' && s[r] != ')') {
            return "no";
        } else if (s[l] == '{' && s[r] != '}') {
            return "no";
        } else if (s[l] == '[' && s[r] != ']') {
            return "no";
        }

        if (s[l] == ')')
        l++;
        r--;
    }
    return "yes";
}

int main() {
    int n;
    cin>>n;
    while (n > 0) {
        string s;
        cin>>s;
        cout<<isBalanced(s)<<"\n";
        n--;
    }
    return 0;
}

