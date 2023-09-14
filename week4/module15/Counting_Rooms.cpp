#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,m;
const int N = 1e3+5;
int vis[N][N];
char a[N][N];

vector<pii>path={{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m && a[i][j]!='#';
}

void dfs(int si,int sj){

    vis[si][sj]=1;
    for(auto [i,j] : path){
        int x=si+i;
        int y= sj+j;
        if(isValid(x,y) && !vis[x][y])
            dfs(x,y);
    }

}

int main(){
     cin>>n>>m;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
     }

     int c=0;
     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j]!='#' && !vis[i][j]){
                c++;
                dfs(i,j);
            }
        }
     }
     cout<<c<<endl;
}