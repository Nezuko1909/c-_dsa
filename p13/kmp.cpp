#include <iostream>
#include <vector>
using namespace std;

// Hàm tính mảng LPS
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // độ dài của tiền tố dài nhất
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Hàm tìm kiếm pattern trong text
void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPSArray(pattern);

    int i = 0; // chỉ số của text
    int j = 0; // chỉ số của pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern được tìm thấy tại vị trí: " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Hàm main
int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AB";
    KMPSearch(text, pattern);
    return 0;
}
