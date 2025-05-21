#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int res = INT_MIN;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur += a[i];
        if (cur < 0) cur = 0;
        if (cur % 2 == 0) res = max(res, cur);
    }
    for (int num : a) {
        if (num % 2) res = max(res, num);
    }
    if (res != INT_MIN) cout << res;
    else cout << "NOT_FOUND";
    return 0;
}