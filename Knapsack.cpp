#include <bits/stdc++.h>
using namespace std;

int knapsack(int B, vector<pair<int, int>> items) {
    vector<int> tab(B + 1, 0);
    for (int i = 1; i <= items.size(); i++) {
        for (int j = B; j >= items[i - 1].second; j--) {
            tab[j] = max(tab[j], tab[j - items[i - 1].second] + items[i - 1].first);
        }
    }
    return tab[B];
}

int main() {
    int n, B;
    cin >> n >> B;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        items.push_back({b, a});
    }
    cout << knapsack(B, items);
    return 0;
}