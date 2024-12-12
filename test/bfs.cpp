#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Hàm tìm kiếm theo chiều rộng (BFS) trên đồ thị không có trọng số.
 * 
 * 1. Tạo danh sách kề (adjacency list) để biểu diễn đồ thị.
 * 
 * 2. Khởi tạo mảng khoảng cách d, gán tất cả giá trị ban đầu là -1 (chưa được thăm).
 * 
 * 3. Khởi tạo hàng đợi để thực hiện BFS, bắt đầu từ đỉnh s.
 * 
 * 4. Duyệt đồ thị:
 * 
 *    - Lặp cho đến khi hàng đợi rỗng.
 * 
 *    - Lấy đỉnh hiện tại ra khỏi hàng đợi.
 * 
 *    - Duyệt tất cả các đỉnh kề của đỉnh hiện tại và cập nhật khoảng cách nếu chưa được thăm.
 * 
 * @param n Số lượng đỉnh trong đồ thị.
 * @param m Số lượng cạnh trong đồ thị.
 * @param edges Danh sách các cạnh của đồ thị, mỗi cạnh là một cặp đỉnh [u, v].
 * @param s Đỉnh xuất phát cho phép tìm kiếm BFS.
 * 
 * @return Mảng khoảng cách từ đỉnh s đến tất cả các đỉnh còn lại, 
 *         trong đó giá trị -1 có nghĩa là không thể đến được từ đỉnh s.
 */
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adj(n + 1);
    for (auto x : edges) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vector<int> d(n + 1, -1);
    queue<int> q;
    d[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int x : adj[cur]) {
            if (d[x] == -1) {
                d[x] = d[cur] + 6;
                q.push(x);
            }
        }
    }

    return d;
}


int main() {
    int n = 4;
    int m = 2;
    vector<vector<int>> edges = {{1, 2}, {1, 3}};
    int s = 1;

    vector<int> result = bfs(n, m, edges, s);

    for (int i = 1; i <= n; ++i) {
        if (i != s) {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    return 0;
}