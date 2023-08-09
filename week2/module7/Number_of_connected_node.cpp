#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}

const int N =1e6;
vector<int>g[N];
bool vis[N];

void dfs(int u){
    vis[u]=true;
    for(auto v:g[u]){
        if(!vis[v]){ 
            dfs(v);
        }
    }
}

void bfs(int s)
{
    queue<int>q;
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
        }
    }
}

int main(){
     int n,e;
     cin>>n>>e;
     int u,v;
     for(int i=1;i<=e;i++){
         cin>>u>>v;
         g[u].push_back(v);
         g[v].push_back(u);
     }


     int c=0;
     for(int i=1;i<=n;i++){
        if(!vis[i]){ 
            c++;
            // bfs(i);
            dfs(i);
        }
     }
     cout<<c<<endl; 
}