#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}
const int INF = 1e7+10;
int main(){
    int n;
    cin>>n;
     int dis[n+1][n+1];
     
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dis[i][j];
            if(dis[i][j]==-1){
                 dis[i][j]=INF;
            }
        }
     }

     for(int k=1;k<=n;k++){
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
     }
     int mx=0;
     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j]<INF)mx=max(mx, dis[i][j]);
        }
     }
     cout<<mx<<endl;
}