#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }

//* O(n+m)
    void bfs(int s, int d)
    {
        int dis[V];
        memset(dis, -1, sizeof(dis));
        bool vis[V];
        memset(vis, false, sizeof(vis));
        int parent[V];
        parent[s] = -1;


        queue<int> q;
        q.push(s);
        dis[s] = 0;


        while (!q.empty())
        {
            int u = q.front();
            // cout << u << endl;
            q.pop();
            vis[u] = true;
            for (auto v : l[u])
            {
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                    dis[v] = dis[u] + 1;
                    parent[v] = u;
                }
            }
        }

        cout <<"Distance : "<< dis[d] << endl;

        /* for(int i=1;i<V;i++){
           cout<<"parent of "<<i<<"-> "<<parent[i]<<endl;
        } */

//* Path Finding O(n)
        vector<int> path;
        int curr = d;

        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());
        cout << "Path ";
        for (auto node : path)
        {
            cout << node << " ";
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
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    // g.printAdjList();

    int s, d;
    cin >> s >> d;
    g.bfs(s, d);
}
