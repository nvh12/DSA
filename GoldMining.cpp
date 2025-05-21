#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> tab(n);
    for (int i = 0; i < l1; ++i) {
        tab[i] = a[i];
    }
    for (int i = l1; i < n; i++)  {
        for (int j = l1; j <= l2 && ((i - j) > -1); j++) {
            tab[i] = max(tab[i], tab[i - j] + a[i]);
        }
    }
    cout << *max_element(tab.begin(), tab.end());
    return 0;
}