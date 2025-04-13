#include <bits/stdc++.h>
using namespace std;
#define MAX 32
int K, n, Q, R, segment = 0, nbR = 0, f = 0, fBest = INT_MAX, Cmin = INT_MAX;
vector<int> y, x, d, load, visited;
vector<vector<int>> c;

bool checkX(int v, int k)
{
    if (v > 0 && visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}

void TryX(int s, int k)
{
    if (s == 0)
    {
        if (k < K)
            TryX(y[k + 1], k + 1);
        return;
    }
    else
    {
        for (int v = 0; v <= n; v++)
        {
            if (checkX(v, k))
            {
                x[s] = v;
                visited[v] = 1;
                f += c[s][v];
                load[k] += d[v];
                segment++;
                if (v == 0)
                {
                    if (k == K)
                    {
                        if (segment == n + nbR)
                            fBest = min(f, fBest);
                    }
                    else
                    {
                        if (f + (n + nbR - segment) * Cmin < fBest)
                            TryX(y[k + 1], k + 1);
                    }
                }
                visited[v] = 0;
                f -= c[s][v];
                load[k] -= d[v];
                segment--;
            }
        }
    }
}

bool check(int v, int k)
{
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if (d[v] + load[k] > Q)
        return false;
    return true;
}

void TryY(int k)
{
    int start = 0;
    if (y[k - 1] > 0)
        start = y[k - 1] + 1;
    for (int v = start; v <= n; v++)
    {
        if (check(v, k))
        {
            y[k] = v;
            if (v > 0)
            {
                visited[v] = 1;
                f += c[0][v];
                load[k] += d[v];
                segment++;
            }
            if (k < K)
                TryY(k + 1);
            else
            {
                nbR = segment;
                TryX(y[1], 1);
            }
            if (v > 0)
            {
                visited[v] = 0;
                f -= c[0][v];
                load[k] -= d[v];
                segment--;
            }
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
    c = vector<vector<int>>(MAX, vector<int>(MAX));
    y = vector<int>(MAX);
    x = vector<int>(MAX);
    visited = vector<int>(MAX, 0);
    d = vector<int>(MAX);
    load = vector<int>(MAX, 0);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] > 0) Cmin = min(Cmin, c[i][j]);
        }
    }
    TryY(1);
    if (fBest < INT_MAX) cout << fBest;
}