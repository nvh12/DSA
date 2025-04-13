#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lines;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back({ a, b});
    }
    sort(lines.begin(), lines.end(), comp);
    int point = -1;
    vector<pair<int, int>> res;
    for (pair<int, int> cur : lines) {
        if (cur.first > point) {
            res.push_back(cur);
            point = cur.second;
        }
        else continue;
    }
    cout << res.size();
}