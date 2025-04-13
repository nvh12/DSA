#include <bits/stdc++.h>
using namespace std;

int n, maxCapacity, res = INT_MAX, minDist = INT_MAX;
vector<vector<int>> distMat;
vector<bool> ck;
vector<int> step;

bool check(int v, int k, int capacity) {
    if (ck[v]) return false;
    if (v > n) {
        if (!ck[v - n]) return false;
    }
    else {
        if (capacity + 1 > maxCapacity) return false;
    }
    return true;
}

void updateRes(int curDist, int curPos) {
    if (curDist + distMat[curPos][0] < res) res = curDist + distMat[curPos][0];
}

void backTrack(int k, int capacity, int curDist) {
    if (curDist >= res) return;
    int prev = step[k - 1];
    for (int i = 1; i <  2 * n + 1; i++) {
        if (check(i, k, capacity)) {
            ck[i] = true;
            curDist += distMat[prev][i];
            step[k] = i;
            if (i <= n) capacity++;
            else capacity--;
            if (k == 2 * n) updateRes(curDist, i);
            else {
                if (curDist + minDist * (2 * n + 1 - k) < res)
                    backTrack(k + 1, capacity, curDist);
            }
            if (i <= n) capacity--;
            else capacity++;
            ck[i] = false;
            curDist -= distMat[prev][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> maxCapacity;
    int capacity = 0;
    ck.assign(2 * n + 1, false);
    distMat.assign(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 0; i < 2  * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> distMat[i][j];
            minDist = min(distMat[i][j], minDist);
        }
    }
    step.assign(2 * n + 1, 0);
    step[0] = 0;
    backTrack(1, capacity, 0);
    cout << res;
}