#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> tab(n);
    tab[0] = a[0];
    tab[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        tab[i] = max(tab[i - 2] + a[i], tab[i - 1]);
    }
    cout << tab[n - 1];
    return 0;
} 