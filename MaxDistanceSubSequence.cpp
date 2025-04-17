#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

bool checkD(vector<int> &V, int d, int c) {
    int count = 1;
    int n = V.size();
    int last = V[0];
    for (int j = 1; j < n; j++) {
        if ((V[j] - last) >= d) {
            count++;
            last = V[j];
            if (count == c) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, c;
        cin >> n >> c;
        vector<int> V(n);
        for (int j = 0; j < n; j++) {
            cin >> V[j];
        }
        sort(V.begin(), V.end(), compare);
        int res = 0;
        int low = 0, high = V[n - 1] - V[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (checkD(V, mid, c)) {
                low = mid + 1;
                res = mid;
            }
            else high = mid - 1;
        }
        cout << res << endl;
    }
}