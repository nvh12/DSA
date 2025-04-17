#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int res = A[0];
    int total = 0;
    for (int num : A) {
        if (total < 0) total = 0;
        total += num;
        res = max(total, res);
    }
    cout << res;
    return 0;
}