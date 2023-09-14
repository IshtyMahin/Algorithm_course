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
vector<vector<int> >g;
vector<bool>vis;

vector<int>reverseBfs(int s)
{
    vector<int>reverseOder;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        reverseOder.push_back(u);
        for(auto v:g[u]){
            if(vis[v])continue;
             vis[v]=true;
             q.push(v);
        }
    }
    return  reverseOder;
}
int main()
{
    int n, e;
    cin >> n >> e;
    g.resize(n + 1);
    vis.resize(n+ 1);
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>ans=reverseBfs(1);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}