#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dis[N];
int vis[N];
vector<int>g[N];

vector<int>cmp;
void dfs(int u){
    vis[u]=1;
    cmp.push_back(u);
    for(auto v:g[u]){
        if(vis[v])continue;
        dis[v] = dis[u] + 1;
        dfs(v);
    }

}
int main(){
     int n,e;
     cin>>n>>e;
     while(e--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
     }

     int cnt=0;
     for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
            for(int val:cmp){
                cout<<val<<" ";
            }
            cout<<endl;
            cmp.clear();
        }
     }
     cout<<cnt<<endl;
}