// dfs -> depth first search

#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

// O(V+E)
void dfs(int vertex)
{
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        if (vis[child])
            continue;

        dfs(child);
    }
}

int depth[N];
int height[N];

// O(V+E)
void dfsFor_depth_height(int vertex)
{

    vis[vertex] = true;
    for (int child : g[vertex])
    {
        if (vis[child])
            continue;

        depth[child] = depth[vertex] + 1;

        dfs(child);

        height[vertex] = max(height[vertex], height[child] + 1);
    }

}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
}