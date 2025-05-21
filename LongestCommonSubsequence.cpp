#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> tab(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            if (a[i - 1] == b[j - 1]) tab[i][j] = max(tab[i][j], tab[i - 1][j - 1] + 1);
        }
    }
    cout << tab[n][m];
    return 0;
} 