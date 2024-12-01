#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    string line;

    cin>>n;
    cin.ignore();
    while (n--) {
        getline(cin, line);
        s+=line + "\n";
    }

    regex emailRegex(R"([a-zA-Z0-9_]+(?:\.[a-zA-Z0-9_]+)*@[a-zA-Z0-9_]+(?:\.[a-zA-Z0-9_]+)+)");
    smatch match;
    set<string> e;

    string::const_iterator searchStart(s.cbegin());
    while(regex_search(searchStart, s.cend(), match, emailRegex)) {
        e.insert(match.str());
        searchStart = match.suffix().first;
    }

    vector<string> ve(e.begin(), e.end());
    for (size_t i = 0; i < ve.size(); i++) {
        cout<<ve[i];
        if (i != ve.size() - 1) {
            cout<<";";
        }
    }
    cout<<endl;
    return 0;
}