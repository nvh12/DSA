#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((a[i] > a[j]) && (res[i] < (res[j] + 1))) {
                res[i] = res[j] + 1;
            }
        }
    }
    cout << *max_element(res.begin(), res.end());
}