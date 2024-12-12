#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    // Tạo mảng c lưu số kẹo, khởi tạo mỗi học sinh có ít nhất 1 viên
    std::vector<int> c(n, 1);

    // Duyệt từ trái sang phải
    for (int i = 1; i < n; i++) {
        // Nếu học sinh hiện tại có điểm cao hơn học sinh trước đó,
        // thì số kẹo của học sinh hiện tại phải nhiều hơn học sinh trước đó
        if (arr[i] > arr[i - 1]) {
            c[i] = c[i - 1] + 1;
        }
    }

    // Duyệt từ phải sang trái
    for (int i = n - 2; i >= 0; --i) {
        // Nếu học sinh hiện tại có điểm cao hơn học sinh tiếp theo,
        // thì số kẹo của học sinh hiện tại phải lớn hơn số kẹo của học sinh tiếp theo.
        // Sử dụng hàm max để đảm bảo giữ nguyên số kẹo đã tính từ lượt duyệt trái sang phải
        if (arr[i] > arr[i + 1]) {
            c[i] = max(c[i], c[i + 1] + 1);
        }
    }

    // Tính tổng số kẹo cần phát
    // Mảng c hiện tại đã lưu số kẹo tối thiểu cho từng học sinh
    long s = 0;
    for (int candy : c) {
        s += candy; // Cộng dồn số kẹo của từng học sinh vào biến tổng
    }
    return s; // Trả về tổng số kẹo tối thiểu
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
