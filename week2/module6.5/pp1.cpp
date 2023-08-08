#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}
const int N = 1e6;
vector<int>g[N];
bool vis[N];
void dfs(int u){
      vis[u]=true;
      for(auto v:g[u]){
        if(vis[v])continue;
        dfs(v);
      }
      cout << u << " ";
}
int main(){
     int n,e;
     cin>>n>>e;
     for(int i=1;i<=e;i++){
         int u,v;
         cin>>u>>v;
         g[u].push_back(v);
         g[v].push_back(u);
     }
     dfs(1);
}