#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
int level[N];
vector<int> v;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}
int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int s, d;
        cin >> s >> d;
        for (int i = 0; i <= N; i++)
        {
            level[i] = -1;
            visited[i] = false;
        }
        bfs(s);
        cout << level[d] << endl;
        

    }
}