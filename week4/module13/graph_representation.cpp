#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}


int main(){
     int n,e;
     cin>>n>>e;
     int adj[n+1][n+1];
     /* for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            adj[i][j]=0;
        }
     } */
     memset(adj,0,sizeof(adj));
     
     while(e--){
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
     }

     for (int i = 0; i <= n; i++)
     {
        for (int j = 0; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
     }
}