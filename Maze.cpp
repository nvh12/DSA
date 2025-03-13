#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    queue<pair<int, int>> Q;
    Q.push({r - 1, c - 1});
    visited[r - 1][c - 1] = 1;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        int x = cur.first;
        int y = cur.second;
        Q.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            cout << dist[x][y] + 1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (x + dr[i] < n && x + dr[i] > -1 &&
                y + dc[i] < m && y + dc[i] > -1 &&
                matrix[x + dr[i]][y + dc[i]] == 0 && visited[x + dr[i]][y + dc[i]] == 0) {
                Q.push({x + dr[i], y + dc[i]});
                visited[x + dr[i]][y + dc[i]] = 1;
                dist[x + dr[i]][y + dc[i]] = dist[x][y] + 1;
            }
        }
    }
    cout << -1;
}