#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 6;
vector<pii> g[N];

void adjList(int e)
{
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}
void printAdjList(int e){
    for (int i = 1; i <= e; i++)
    {
        cout << "List " << i << ": ";
        for (auto [e, w] : g[i])
        {
            cout << "(" << e << ", " << w << "), ";
        }
        cout << endl;
    }
}

int adjmat[N][N];
void adjmatrix(int e)
{
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjmat[u][v] = w;
        adjmat[v][u] = w;
    }
}

void printAdjmatrix(int e){
    for (int i = 1; i <= e; i++)
    {
        for (int j = 1; j <= e; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (auto [e, w] : g[i])
        {
            cout << "(" << e << ", " << w << "), ";
        }
        cout << endl;
    }
}