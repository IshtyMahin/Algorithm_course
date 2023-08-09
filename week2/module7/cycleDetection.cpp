#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()

const int N = 1e6;
vector<int> g[N];
bool vis[N];


bool dfs(int u,int p=-1)
{
    bool cycleExists = false;
    vis[u] = true;
    
    for (auto v : g[u])
    {
        if(v==p)continue;
        if(vis[v])return true;
        cycleExists |= dfs(v, u);
    }
    return cycleExists;
}

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

  /*  for(int i=1;i<=n;i++){
    if(!vis[i]){
        if (dfs(1))
        {
            cout << "cycle exists" << endl;
            return 0;
        }
    }
   }
  
    cout<<"cycle doesn't exists"<<endl; */

    bool isCycle= false;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        isCycle |=dfs(i);
    }

    if(isCycle)cout<<"Cycle detected!";
    else cout<<"No Cycles detected!";

  return 0;
}