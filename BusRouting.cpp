#include <bits/stdc++.h>
using namespace std;

bool check(int v, int k, vector<bool>& ck, int capacity, int n, int max) {
    if (ck[v]) return false;
    if (v > n) {
        if (!ck[v - n]) return false;
    }
    else {
        if (capacity + 1 > max) return false;
    }
    return true;
}

void updateRes(int& res, vector<vector<int>>& distance, int curDist, int curPos) {
    if (curDist + distance[curPos][0] < res) res = curDist + distance[curPos][0];
}

void backTrack(int k, vector<int>& step, vector<vector<int>>& distance, vector<bool>& ck, int n, int capacity, int curDist, int& res, int minDist, int max) {
    for (int i = 1; i <  2 * n + 1; i++) {
        if (check(i, k, ck, capacity, n, max)) {
            ck[i] = true;
            curDist += distance[step[k - 1]][i];
            step[k] = i;
            if (i <= n) capacity += 1;
            else capacity -= 1;
            if (k == 2 * n) updateRes(res, distance, curDist, i);
            else {
                if (curDist + minDist * (2 * n + 1 - k) < res)
                    backTrack(k + 1, step, distance, ck, n, capacity, curDist, res, minDist, max);
            }
            if (i <= n) capacity -= 1;
            else capacity += 1;
            ck[i] = false;
            curDist -= distance[step[k - 1]][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int res = INT_MAX;
    int n;
    cin >> n;
    int max;
    cin >> max;
    int capacity = 0;
    vector<bool> ck(2 * n + 1, false);
    int minDist = INT_MAX;
    vector<vector<int>> distance(2 * n + 1, vector<int>(2 * n + 1, INT_MAX));
    for (int i = 0; i < 2  * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> distance[i][j];
            minDist = min(distance[i][j], minDist);
        }
    }
    vector<int> step(2 * n + 1);
    step[0] = 0;
    backTrack(1, step, distance, ck, n, capacity, 0, res, minDist, max);
    cout << res;
}