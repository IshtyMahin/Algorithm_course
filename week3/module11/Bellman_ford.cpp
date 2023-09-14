#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
#define print(v)                      \
   for (int i = 0; i < v.size(); i++) \
   {                                  \
      cout << v[i] << " ";            \
   }

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
int d[N];
int n, m;

void bellman_ford(int s)
{
   for (int i = 1; i <= n; i++)
   {
      d[i] = INF;
   }

   d[s] = 0;

   for (int i = 1; i < n; i++)
   {
      for (int u = 1; u <= n; u++)
      {
         for (pii vpair : g[u])
         {
            int v = vpair.first;
            int w = vpair.second;

            if (d[u] != INF && d[v] > d[u] + w)
            {
               d[v] = d[u] + w;
            }
         }
      }
   }
}

void bellman_ford2(int s)
{
   for (int i = 1; i <= n; i++)
   {
      d[i] = INF;
   }

   d[s] = 0;

   for (int i = 1; i < n; i++)
   {
      // all edges relaxation
      for (auto [edge,w] : list_of_edges)
      {
         auto [u,v]=edge;
         if(d[u]!=INF && d[v]>d[u]+w)
             d[v]=d[u]+w;
      }
   }
}



int main()
{

   cin >> n >> m;

   while (m--)
   {
      int u, v, w;
      cin >> u >> v >> w;

      //for bellman_ford1
      g[u].push_back({v, w});

      // for bellman_ford2
      list_of_edges.push_back({{u, v}, w});
   }

   bellman_ford2(1);
   for (int i = 1; i <= n; i++)
   {
      cout << "Distance of " << i;
      cout << ": " << d[i] << endl;
   }
}


/* limitation 
    => negative cycle
*/