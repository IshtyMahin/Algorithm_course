// Dijkstra algorithm => Single source shortest path

// path relexation

// BFS -> O(N+E)
// DFS -> O(N+E)

// Navie dijkstra -> O(N*E)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> g[N];
int dis[N];
int c=0;
void navieDijkstra(int s)
{
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        c++;

        int u = q.front();
        q.pop();
        for (auto [v, w] : g[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push(v);
            }
        }
    }
}


int vis[N]={0};
typedef pair<int, int> pii;

//O(V+ElogV)
void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;

    dis[s] = 0;
    q.push({0,s});
    
    while (!q.empty())
    {

        auto [uw,u] = q.top();
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u] = 1;
        // c++;
        for (auto [v, vw] : g[u])
        {
            if (uw + vw < dis[v])
            {
                dis[v] = uw + vw;
                q.push({dis[v],v}); //log n
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    
    for(int i =1;i<=n;i++){
        dis[i]=INT_MAX;
    }

    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " => " << dis[i] << endl;
    } 

    // cout<<c<<endl;
}