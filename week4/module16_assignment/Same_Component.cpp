#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
# define print(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}

int n, m;
const int N = 1e3+10;
int vis[N][N];
char grid[N][N];
vector<pair<int,int>>path={{0,-1},{0,1},{-1,0},{1,0}};
bool isValid(int ci,int cj){
    return ci>=0 && ci<n && cj>=0 && cj<m;
}
void dfs(int si,int sj){
    vis[si][sj]=1;

    for(auto [x,y]:path){
        int ci = x+si,cj= y+sj;
        if(isValid(ci,cj)&& grid[ci][cj]=='.' && !vis[ci][cj]){
            dfs(ci,cj);
        }
    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    dfs(si,sj);
    if(vis[di][dj]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

     
}