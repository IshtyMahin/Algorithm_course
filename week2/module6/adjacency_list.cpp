#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}

const int N = 1e5+6;
vector<pair<int,int>>adj[N];

int main(){
     int n,m;
     cin>>n>>m;

     for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
     }

     for(int i=1;i<=n;i++){
        cout<<"List "<<i<<": ";
        for(auto [e,w]:adj[i]){
            cout<<"("<<e<<", "<<w<<"), ";
        }
        cout<<endl;
     }
}