#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int N=1e3+5;
int vis[N][N];
int dis[N][N];

vector<pii>path={{-1,0},{1,0},{0,-1},{0,1}};

int n, m;

bool isValid(int ci,int cj){
    return ci >= 0 && ci < n && cj >= 0 && cj < m;
}

void bfs(int si,int sj){
    queue<pii>q;
    q.push({si,sj});
    dis[si][sj]=0;
    vis[si][sj]=1;

    while(!q.empty()){

        auto [pi,pj]  = q.front();
        q.pop();

        for(auto [i,j] : path ){
             int ci = pi+i;
             int cj = pj+j;
             if(isValid(ci,cj) && !vis[ci][cj]){
                 vis[ci][cj]=1;
                 q.push({ci,cj});
                 dis[ci][cj]=dis[pi][pj]+1;
             }
        }
    }

}

int main(){
   
    cin>>n>>m;
    
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dis[i][j]<<" ";   
        }
        cout<<endl;
    }
}