#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9
class Graph
{
    int V;
    list<pii> *l; // Use a pair to store vertex and weight

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int i, int j, int w, bool undir = true)
    {
        l[i].push_back({j, w});
        if (undir)
        {
            l[j].push_back({i, w});
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto edge : l[i])
            {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(int source)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INF);
        vector<int> vis(V, false);

        dist[source] = 0;
        pq.push({dist[source], source});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            vis[u] = true;

            for (auto [v,w] : l[u])
            {

                if (vis[v])
                    continue;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if(vis[i])
            cout << "Distance of " << i << " from 1 --> " << dist[i] << endl;
        }
    }

    
};

int main()
{
    int n;
    cin >> n;
    Graph g(n + 1);
    int e;
    cin >> e;
    int u, v, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w,false);
    }
    // g.printAdjList();
    g.dijkstra(1);
}
