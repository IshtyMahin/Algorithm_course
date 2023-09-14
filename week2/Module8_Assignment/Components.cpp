#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> adj[N];
bool visited[N];
int component[1001];
int c = 0;
void dfs(int u)
{
    visited[u] = true;
    c++;
    for (int v : adj[u])
    {

        if (visited[v])
            continue;

        dfs(v);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        q.push(u);
        q.push(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int j = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (visited[i])
            continue;
        dfs(i);
        component[j] = c;
        j++;
        c = 0;
    }
    cout<<j<<endl;
    sort(component, component + j);
    for (int i = 0; i < j; i++)
    {
        cout << component[i] << " ";
    }
}