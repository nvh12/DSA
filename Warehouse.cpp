#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, T, D; 
    cin >> n >> T >> D;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    int res = 0;
    vector<vector<int>> tab(n, vector<int> (T + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = t[i]; j <= T; j++) {
            tab[i][j] = a[i];
            for (int k = i - 1; k >= (i - D) && k >= 0; k--) {
                if (j - t[i] >= 0)
                    tab[i][j] = max(tab[k][j - t[i]] + a[i], tab[i][j]);
            }
            res = max(res, tab[i][j]);
        }
    }
    cout << res;
    return 0;
}