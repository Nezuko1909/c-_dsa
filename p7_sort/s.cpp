#include <iostream>
#include <vector>

using namespace std;

// Hàm phân đoạn (partition): Chia mảng thành hai phần dựa trên pivot
int pt(vector<int>& a, int l, int h) {
    int p = a[h];  // Chọn pivot là phần tử cuối cùng
    int i = l - 1; // Vị trí cuối cùng của vùng nhỏ hơn pivot

    // Duyệt qua các phần tử từ l đến h-1
    for (int j = l; j < h; j++) {
        if (a[j] < p) { // Nếu phần tử nhỏ hơn pivot
            i++; // Mở rộng vùng nhỏ hơn pivot
            swap(a[i], a[j]); // Đưa phần tử nhỏ hơn vào vùng bên trái
        }
    }
    // Đặt pivot vào đúng vị trí, sau tất cả các phần tử nhỏ hơn
    swap(a[i + 1], a[h]);

    return i + 1; // Trả về chỉ số của pivot
}

// Hàm QuickSort: Sắp xếp mảng theo phương pháp chia để trị
void quickSort(vector<int>& a, int l, int h) {
    if (l < h) { // Điều kiện dừng: Khi l >= h, đoạn mảng không còn phần tử nào để sắp xếp
        int ptt = pt(a, l, h); // Phân đoạn mảng và lấy vị trí của pivot

        // Đệ quy sắp xếp phần bên trái (nhỏ hơn pivot)
        quickSort(a, l, ptt - 1);

        // Đệ quy sắp xếp phần bên phải (lớn hơn pivot)
        quickSort(a, ptt + 1, h);
    }
}

void selectionSort(int n, int a[]) {
    cout<<"\nSelection Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        int minI = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minI]) {
                minI = j;
            }
        }

        swap(a[i], a[minI]);
        
        for (int i = 0; i < n; i++) {
            cout<<a[i]<<" ";
        }
        cout << endl;
    }
}

void insertSort(int n, int a[]) {
    cout<<"\nInsert Sort:\n";
    for (int i = 1; i < n; i++) {
        int k = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = k;
        
        for (int i = 0; i < n; i++) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int a1[n];
    int a2[n];
    vector<int> a3 = {};

    for (int i = 0; i < n; i++) {
        a1[i] = a[i];
        a2[i] = a[i];
        a3.push_back(a[i]);
    }

    insertSort(n, a1);
    selectionSort(n, a2);

    cout<<"\nQuickSort:\n";
    quickSort(a3, 0, a3.size() - 1);
    for (auto x : a3) {
        cout<<x<<" ";
    }
    
    return 0;
}