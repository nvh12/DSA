#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
vector<int> graph[MAXN];
int num[MAXN], low[MAXN], parent[MAXN];
bool visited[MAXN], articulation[MAXN];
int timer = 1;
int bridges = 0;

void DFS(int u) {
    visited[u] = true;
    num[u] = low[u] =  timer++;
    int children = 0;
    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            children++;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) bridges++;
            if (parent[u] == -1 && children > 1) articulation[u] = true;
            if (parent[u] != -1 && low[v] >= num[u]) articulation[u] = true;
        } else if (v != parent[u]) low[u] = min(low[u], num[v]);
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < vertices; i++) {
        graph[i].clear();
        visited[i] = false;
        parent[i] = -1;
        articulation[i] = false;
    }
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    timer = 1;
    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) DFS(i);
    }
    int articulationCount = 0;
    for (int i = 1; i <= vertices; i++) {
        if (articulation[i]) articulationCount++;
    }
    cout << articulationCount << ' ' << bridges;
    return 0;
}