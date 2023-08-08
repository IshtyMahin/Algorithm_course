/*
!Unreachable Nodes
* You have been given a graph consisting of N nodes and M edges. The nodes in this graph are enumerated from 1 to N . The graph can consist of self-loops as well as multiple edges. This graph consists of a special node called the head node. You need to consider this and the entry point of this graph. You need to find and print the number of nodes that are unreachable from this head node.

! Input Format

* The first line consists of a 2 integers N and M denoting the number of nodes and edges in this graph. The next M lines consist of 2 integers a and b denoting an undirected edge between node a and b. The next line consists of a single integer x denoting the index of the head node.

! Output Format *:

*You need to print a single integer denoting the number of nodes that are unreachable from the given head node.

! Constraints
   1<= N <= 1e5
   1<= M <= 1e5
   1<= x <= N

 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}
const int N = 1e5;
vector<int>g[N];
bool vis[N];
void dfs(int u){
    vis[u]=true;
    for(auto v:g[u]){
        if(vis[v])continue;
        dfs(v);
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

     int x;
     cin>>x;
     dfs(x);
     int c=0;
     for(int i=1;i<=n;i++){
         if(vis[i])c++;
     }
     cout<<n-c<<endl;
}