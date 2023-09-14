#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:

    int vis[100][100];
    int mx=0,c=0;
    int n,m;

    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }

    vector<pair<int,int>>path={{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int si, int sj, vector<vector<int>> grid)
    {
        vis[si][sj] = 1;
        c++;
        for (auto [x, y] : path)
        {
            int ci=x+si,cj=y+sj;
              if(isValid(ci,cj) && grid[ci][cj]==1 && !vis[ci][cj]){
                dfs(ci,cj,grid);
              }
          }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
         n = grid.size();
         m = grid[0].size();
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid);
                    mx=max(mx,c);
                    c=0;
                }
            }
         }
    }
};