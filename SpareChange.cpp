#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> change(n);
    for (int i = 0; i < n; i++) {
        cin >> change[i];
    }
    vector<int> tab(X + 1, INT_MAX);
    tab[0] = 0;
    for (int num : change) {
        for (int i = num; i <= X; i++) {
            if (tab[i - num] != INT_MAX)
                tab[i] = min(tab[i - num] + 1, tab[i]);
        }
    }
    cout << ((tab[X] == INT_MAX) ? -1 : tab[X]);
    return 0;
}