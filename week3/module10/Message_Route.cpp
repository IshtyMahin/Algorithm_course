#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> gr[N];
int vis[N] = {0};
vector<int> level(N, 0);
vector<int> parent(N, -1);

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0;
    vis[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : gr[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
                parent[v] = u;
                level[v] = level[u] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    bfs(1);
    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << level[n] + 1 << endl;
        int cur = n;
        vector<int> path;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = parent[cur];
        }

        reverse(path.begin(), path.end());
        for (auto i : path)
        {
            cout << i << " ";
        }
    }
    

    return 0;
}