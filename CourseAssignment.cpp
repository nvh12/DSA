#include <bits/stdc++.h>
using namespace std;

int m, n;

bool check(int k, int v, vector<vector<int>>& teacherMat, vector<vector<int>>& conflict, vector<int>& assign) {
    if (find(teacherMat[v].begin(), teacherMat[v].end(), k) == teacherMat[v].end()) return false;
    for (int i = 0; i < n; i++) {
        if (assign[i] == v && conflict[k][i] == 1) return false;
    }
    return true;
}

void backtrack(int k, int& res, vector<vector<int>>& teacherMat, vector<vector<int>>& conflict, vector<int>& assign, vector<int>& load) {
    if (k == n) { 
        res = min(res, *max_element(load.begin(), load.end()));
        return;
    }
    for (int i = 0; i < m; i++) {
        if (check(k, i, teacherMat, conflict, assign)) {
            assign[k] = i;
            load[i]++;
            int cur = *max_element(load.begin(), load.end());
            backtrack(k + 1, res, teacherMat, conflict, assign, load);
            assign[k] = -1;
            load[i]--;
        }
    }
}

int main()
{
    int k;
    cin >> m >> n;
    vector<vector<int>> teacherMat(m, vector<int>());
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            teacherMat[i].push_back(a - 1);
        }
    }
    cin >> k;
    vector<vector<int>> conflict (n, vector<int> (n, 0));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        conflict[a - 1][b - 1] = 1;
        conflict[b - 1][a - 1] = 1;
    }
    vector<int> assign(n, -1);
    vector<int> load(m, 0);
    int res = INT_MAX;
    backtrack(0, res, teacherMat, conflict, assign, load);
    cout << res;
}