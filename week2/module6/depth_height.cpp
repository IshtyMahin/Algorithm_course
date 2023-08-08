#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}

const int N = 1e5+10;

vector<int>g[N];
bool vis[N];

int depth[N];
int height[N];

//O(V+E)
void  dfs(int vertex){

    // Take  action on vertex after entering the vertex
    // cout<<vertex<<nl;
    vis[vertex]=true;
    for(int child: g[vertex]){
        //take action on child before entering the child node
        if(vis[child]) continue;
        // cout<<"par "<<vertex<<" ,child"<<child<<nl;
        depth[child]=depth[vertex]+1;
        
        dfs(child);
        
        //take action on child after exiting child node
        height[vertex] = max(height[vertex],height[child]+1);
    }

    //takee action on vertex before exiting the vertex
   
}
int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
         cout<<"Depth of Node "<<i<<" : "<<depth[i]<<endl;
         cout<<"Height of Node "<<i<<" : "<<height[i]<<endl<<endl;

    }
}