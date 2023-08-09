#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()


const int N = 1e6;
vector<int> g[N];
bool vis[N];

//* for connected component
vector<vector<int>>vc;
vector<int>tmp;

void dfs(int u)
{
    tmp.push_back(u);
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
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

    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            tmp.clear();
            dfs(i);
            vc.push_back(tmp);
        }
    }
    
    cout<<"Number of connected components: "<<vc.size()<<endl;
    for(int i=0;i<vc.size();i++){
        cout<<"Component "<<i+1<<": ";
        for(auto p:vc[i]){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}