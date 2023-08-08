#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}
const int N = 1e3 + 5;
int adjmat[N][N];
vector<int>adjL[N];
int main(){
     int n;
     cin>>n;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adjmat[i][j];
        }
     }

     for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= n; j++)
        {
            if(adjmat[i][j]==1)
                adjL[i].push_back(j);
        }
     }

     for(int i=1;i<=n;i++){
        cout<<"List "<<i<<" : ";
        for(auto v:adjL[i]){
            cout<<v<<" ";
        }
        cout << endl;
     }
}