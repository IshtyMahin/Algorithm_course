#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dis[N];
int vis[N];
int par[N];
vector<int>g[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    par[s]=-1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:g[u]){
            if(!vis[v]){
                q.push(v);
                par[v]=u;
                dis[v]=dis[u]+1;
                vis[v]=1;
            }
        }
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

     bfs(1);

     /* for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<" : "<<par[i]<<endl;
     } */
     int d;
     cin>>d;
     if(vis[d]){
        int x=d;
        vector<int>path;
        while(x!=-1){
            cout<<x<<" ->";
            path.push_back(x);
            x=par[x];
        }
        cout<<endl;
        reverse(path.begin(),path.end());
        for(auto p:path){
            cout << p << " ";
        }
       
     }
     else
     {
        cout << "Path nai" << endl;
     }
}