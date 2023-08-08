//* https://www.eolymp.com/en/contests/9116/problems/79186

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }

const int N = 1e3;
// int adj[N][N];
vector<int> g[N];
bool vis[N];

set<pair<int,int>>pv;
void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!(v != u && vis[v]))
        {
            pv.insert({u, v});
        }

        if (!vis[v])
            dfs(v); 
    }
}

int main()
{
    int n,e;
    cin >> n>>e;
    int u,v;
    for (int i = 1; i <= e; i++)
    {
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
    }
    dfs(1);
    for(auto [u,v]:pv){
        cout<<u<<" "<<v<<endl;
    }
    
}