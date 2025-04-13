#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> arr, int h) {
    int res = 0;
    for (int x : arr) {
        if (x > h) res += x - h;
    }
    return res;
}

int main() {
    int n, m, res;
    cin >> n >> m;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    int high = *max_element(height.begin(), height.end());
    int low = 0;
    while (high >= low) {
        int mid = (high + low) / 2;
        int a = calc(height, mid);
        if (a >= m) {
            low = mid + 1;
            res = mid;
        }
        else if (a < m) high = mid - 1;
    }
    cout << res;
}