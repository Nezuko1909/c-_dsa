#include <iostream>
#include <vector>

using namespace std;

int main() {
    int req;
    cin >> req;

    string s = "";
    vector<string> ver = {};
    ver.push_back(s);

    while (req > 0) {
        int func;
        cin >> func;

        if (func == 1) {  // append
            string aps;
            cin >> aps;
            s += aps;
            ver.push_back(s);
        } 
        else if (func == 2) {  // delete the last k characters of s
            int k;
            cin >> k;
            if (k > s.length()) {
                k = s.length();  
            }
            s.erase(s.end() - k, s.end());  
            ver.push_back(s);
        }
        else if (func == 3) {  // print
            int k;
            cin >> k;
            if (k > 0 && k <= s.length()) {
                cout << s[k - 1] << "\n";  
            }
        }
        else if (func == 4) {  // undo
            ver.pop_back();
            s = ver[ver.size() - 1];
        }
        req--;
    }
}
