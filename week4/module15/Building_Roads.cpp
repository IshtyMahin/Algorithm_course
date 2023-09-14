#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int>g[N];
int vis[N];
vector<vector<int>>v;
vector<int>tmp;
void dfs(int s){
    vis[s]=1;
    tmp.push_back(s);
    for(auto v:g[s]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
     int n,m;
     cin>>n>>m;
     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
     }

     for(int i=1;i<=n;i++){
         if(!vis[i]){
            dfs(i);
            v.push_back(tmp);
            tmp.clear();
         }
     }
     int x = v.size() - 1;
      cout <<x << endl;
     for(int i=0;i<x;i++){
        cout<<v[i][0]<<" "<<v[i+1][0]<<endl;
     }
}