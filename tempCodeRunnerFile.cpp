#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int res = INT_MIN;
    int prefixSum = 0;
    vector<int> minParity(2, INT_MAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefixSum += a[i];
        int m = prefixSum % 2;
        if (minParity[m] != INT_MAX) {
            res = max(res, prefixSum - minParity[m]);
        }
        minParity[m] = min(minParity[m], prefixSum);
    }
    if (res != INT_MIN) cout << res;
    else cout << "NOT_FOUND";
    return 0;
}