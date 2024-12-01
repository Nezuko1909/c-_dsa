#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string trim(string &str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos) return ""; 
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

int main() {
    int n;
    string html;
    string line;

    cin>>n;
    cin.ignore();
    while (n--) {
        getline(cin, line);
        html+=line + "\n";
    }

    regex linkRegex(R"(<a\s+[^>]*href\s*=\s*['"]([^'"]+)['"][^>]*>(.*?)</a>)");
    regex tagRegex(R"(<[^>]*>)");
    smatch match;
    string::const_iterator searchStart(html.cbegin());

    while(regex_search(searchStart, html.cend(), match, linkRegex)) {
        string url = match[1];
        string text = match[2];

        text = regex_replace(text, tagRegex, "");
        
        url = trim(url);
        text = trim(text);

        cout<<url<<","<<text<<endl;
        searchStart = match.suffix().first;
    }
    return 0;
}