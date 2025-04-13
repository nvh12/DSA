#include <bits/stdc++.h>
using namespace std;

void backtrack(int& res, int k, vector<int>& a, vector<int>& sum, int f, int n, int M) {
    if (k == (n + 1) && f == M) {
        res++;
        return;
    }
    if (a[k] == 0) return;
    int lim = (M - f - (sum[n] - sum[k])) / a[k];
    if (lim < 0) return;
    for (int i = 1; i <= lim; i++) {
        backtrack(res, k + 1, a, sum, f + a[k] * i, n, M);
    }
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 1), sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int res = 0;
    backtrack(res, 1, a, sum, 0, n, M);
    cout << res;
}