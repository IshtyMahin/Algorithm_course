// breadth first search ->  BFS

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()

const int N = 1e6;
vector<int> g[N];
queue<int> q;
int dis[N];
bool vis[N];

void bfs(int s)
{
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {

        int u = q.front();
        q.pop();

        for (auto v : g[u])
        {
            if (vis[v])
                continue;
            q.push(v);
            vis[v] = true;
            dis[v] = dis[u] + 1;
        }
    }
}

// V -node , E - edges
// O(V+E) =>BFS

int main()
{
    int n, e;
    cin >> n >> e;
    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
}