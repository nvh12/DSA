#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> tab(2, vector<int> (n, 0));
    tab[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0) tab[0][i] = tab[1][i - 1];
        for (int len = k1; len <= k2; len++) {
            int j = i - len + 1;
            if (j < 0) continue;
            if (j == 0) tab[1][i] = (tab[1][i] + 1) % MOD;
            else tab[1][i] = (tab[1][i] + tab[0][j - 1]) % MOD;
        }
    }
    cout << (tab[0][n - 1] + tab[1][n - 1]) % MOD;
    return 0;
}