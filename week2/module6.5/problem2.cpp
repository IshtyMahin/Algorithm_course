/*
   * Undirected graph without loops and multiple edges is given with the adjacency matrix. Determine whether the graph is a tree.

    ! Input data
    * The first line contains the number of vertices n (1 ≤ n ≤ 100) in the graph. In the next lines the adjacency matrix of size n × n is given, where 1 denotes the presence of an edge, and 0 its absence. The matrix is symmetric with respect to the main diagonal.

    ! Output data
    * Print the message YES, if the graph is a tree, and NO otherwise.
 */


#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}

const int N = 1e3;
// int adj[N][N];
vector<int>g[N];
bool vis[N];

void dfs(int u){
    vis[u]=true;
    for(auto v:g[u]){
        if(!vis[v])dfs(v);
    }
}

int main(){
     int n;
     cin>>n;
     int x;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x==1)g[i].push_back(j);
        }
     }
     dfs(1);
     int c=0;
     for(int i=1;i<=n;i++){
        c+=g[i].size();
     }

     bool tree=true;

     for(int i=1;i<=n;i++){
        if(!vis[i]){tree=false; break;}
     }

     if(tree and c/2==n-1){
        cout<<"YES";
     }
     else cout<<"NO";




}