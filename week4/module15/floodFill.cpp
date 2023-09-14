#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;





class Solution
{
  public:
      const int N = 100;
      int vis[100][100];
      vector<pair<int, int>> path = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
      int n, m;
      bool isValid(int i, int j)
      {
          return i >= 0 && i < n && j >= 0 && j < m ;
      }

      void dfs(int si, int sj, int src, int c, vector<vector<int>> &image)
      {
          vis[si][sj] = 1;
          if(src==image[si][sj])image[si][sj]=c;
          for(auto [x,y] :path){
            int ci = si+x , cj = sj+y;
            if(isValid(ci,cj)&& image[ci][cj]==src && !vis[ci][cj]){
                dfs(ci, cj, src, c,image);
            }
          }
      }
      vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
      {
        n=  image.size();
        m = image[0].size();
        dfs(sr, sc, image[sr][sc], color, image);
      }
};