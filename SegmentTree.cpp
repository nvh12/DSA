#include <bits/stdc++.h>
using namespace std;

void build(vector<int>& segmentTree, int id, int l, int r, vector<int>& a) {
    if (l == r) {
        segmentTree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(segmentTree, id * 2, l, mid, a);
    build(segmentTree, id * 2 + 1, mid + 1, r, a);
    segmentTree[id] = max(segmentTree[id * 2], segmentTree[id * 2 + 1]);
}

void update(vector<int>& segmentTree, int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        segmentTree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(segmentTree, id * 2, l, mid, pos, val);
    update(segmentTree, id * 2 + 1, mid + 1, r, pos, val);
    segmentTree[id] = max(segmentTree[id * 2], segmentTree[id * 2 + 1]);
}

int query(vector<int>& segmentTree, int id, int l, int r, int a, int b) {
    if (a > r || b < l) return INT_MIN;
    if (a <= l && b >= r) return segmentTree[id];
    int mid = (r + l) / 2;
    int lmax = query(segmentTree, id * 2, l, mid, a, b);
    int rmax = query(segmentTree, id * 2 + 1, mid + 1, r, a, b);
    return max(lmax, rmax);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<int> segmentTree(4 * n);
    build(segmentTree, 1, 1, n, a);
    bool loop = true;
    for (int i = 0 ; i < q; i++) {
        string input;
        cin >> input;
        if (input == "*") {
            break;
        }
        else if (input == "update") {
            int pos, val;
            cin >> pos >> val;
            a[pos] = val;
            update(segmentTree, 1, 1, n, pos, val);
        }
        else if (input == "get-max") {
            int a, b;
            cin >> a >> b;
            cout << query(segmentTree, 1, 1, n, a , b) << '\n';
        }
    }
    return 0;
}