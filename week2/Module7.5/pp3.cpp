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
const int N = 1e5;
vector<int> g[N];
bool vis[N];
bool dfs(int u, int p = -1)
{
    vis[u] = true;
    bool cycleExists = false;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        if (vis[v])
            return true;
        cycleExists |= dfs(v, u);
    }
    return cycleExists;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool cycleExists= dfs(1);
    
    if (cycleExists)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}