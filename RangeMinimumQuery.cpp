#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> preproccessing(int a[], int n) {
    int row = (int)log2(n) + 1;
    vector<vector<int>> minVal(row, vector<int>(n));
    for(int i = 0; i < n; i++) {
        minVal[0][i] = i;
    }
    for(int i = 1; i < row; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            minVal[i][j] = a[minVal[i - 1][j]] > a[minVal[i - 1][j + (1 << (i - 1))]] ?
            minVal[i - 1][j + (1 << (i - 1))] : minVal[i - 1][j];
        }
    }
    return minVal;
}

int query(vector<vector<int>>& minVal, int l, int r, int a[]) {
    int k = log2(r - l + 1);
    return min(a[minVal[k][l]], a[minVal[k][r - (1 << k) + 1]]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> minVal = preproccessing(a, n);
    int m;
    cin >> m;
    int res = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        res += query(minVal, l, r, a);
    }
    cout << res;
}