#include <bits/stdc++.h>
using namespace std;

void build(vector<int>& segmentTree, int id, int l, int r, int a[]) {
    if (l == r) {
        segmentTree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    int lchild = id * 2;
    int rchild = id * 2 + 1;
    build(segmentTree, lchild, l, mid, a);
    build(segmentTree, rchild, mid + 1, r, a);
    segmentTree[id] = min(segmentTree[lchild], segmentTree[rchild]);
}

void update(vector<int>& segmentTree, int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        segmentTree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    int lchild = id * 2;
    int rchild = id * 2 + 1;
    update(segmentTree, lchild, l, mid, pos, val);
    update(segmentTree, rchild, mid + 1, r, pos, val);
    segmentTree[id] = min(segmentTree[lchild], segmentTree[rchild]);
}

int query(vector<int>& segmentTree, int id, int l, int r, int a, int b) {
    if (a > r || b < l) return INT_MAX;
    if (a <= l && b >= r) return segmentTree[id];
    int lchild = id * 2;
    int rchild = id * 2 + 1;
    int mid = (r + l) / 2;
    int lmin = query(segmentTree, lchild, l, mid, a, b);
    int rmin = query(segmentTree, rchild, mid + 1, r, a, b);
    return min(lmin, rmin);
}

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> segmentTree(4 * n);
    build(segmentTree, 1, 1, n, a);
    bool loop = true;
    while (loop) {
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
        else if (input == "get-min") {
            int a, b;
            cin >> a >> b;
            cout << query(segmentTree, 1, 1, n, a , b);
        }
    }
}