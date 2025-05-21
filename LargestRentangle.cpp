#include <bits/stdc++.h>
using namespace std;

int histogram(vector<int> height) {
    int temp = 0;
    stack<int> S;
    height.push_back(0);
    for (int i = 0; i < height.size(); i++) {
        while (!S.empty() && height[i] < height[S.top()]) {
            int top = S.top();
            S.pop();
            int length = S.empty() ? i : i - S.top() - 1;
            int width = height[top];
            temp = max(temp, length * width);
        }
        S.push(i);
    }
    return temp;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> height(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (i == 0) height[i][j] = matrix[i][j];
            else {
                if (matrix[i][j] == 1) height[i][j] = height[i - 1][j] + 1;
                else height[i][j] = 0;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, histogram(height[i]));
    }
    cout << res;
}
