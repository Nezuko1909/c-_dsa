#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lis(vector<int> a) {
    int n = a.size();
    vector<int> c(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                c[i] = max(c[i], c[j] + 1);
            }
        }
    }

    int max_c = 1;
    int max_pos = 0;
    for (int i = 0; i < n; i++) {
        max_c = max(c[i], max_c);
        max_pos = i;
    }

    vector<int> res;
    res.push_back(a[max_pos]);
    int x = max_pos;
    for (int i = max_pos - 1; i >= 0; i--) {
        if (a[i] < a[max_pos] && c[i] == c[x] - 1) {
            res.push_back(a[i]);
            x = i;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// GPT

vector<int> lis2(vector<int> a) {
    int n = a.size();
    vector<int> c(n, 1);       // c[i]: Độ dài LIS kết thúc tại vị trí i
    vector<int> parent(n, -1); // Lưu chỉ số phần tử trước trong LIS

    // Tính LIS và ghi lại phần tử trước (parent)
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && c[i] < c[j] + 1) {
                c[i] = c[j] + 1;
                parent[i] = j; // Ghi nhận chỉ số phần tử trước
            }
        }
    }

    // Tìm chỉ số của phần tử cuối cùng trong LIS
    int max_len = 0, last_index = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] > max_len) {
            max_len = c[i];
            last_index = i;
        }
    }

    // Truy ngược để tìm dãy LIS
    vector<int> res;
    for (int i = last_index; i != -1; i = parent[i]) {
        res.push_back(a[i]);
    }
    reverse(res.begin(), res.end()); // Đảo ngược dãy để có thứ tự chính xác

    return res;
}

int main() {
    //int n;
    //cin>>n;
    vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60};
    // for(int i = 0; i < n; i++) {
    //     int x;
    //     cin>>x;
    //     a.push_back(x);
    // }

    vector<int> li = lis(a);
    vector<int> li2 = lis2(a);

    for (auto x : li) {
        cout<<x<<" ";
    }
    cout<<endl;
    for (auto x : li2) {
        cout<<x<<" ";
    }

    return 0;
}