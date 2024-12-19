#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto x : adj[cur]) {
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