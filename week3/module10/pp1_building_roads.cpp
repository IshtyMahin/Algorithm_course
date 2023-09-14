// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int vis[N] = {0};
// vector<vector<int>> v;
// vector<int>tmp;
void dfs(int s)
{
    // tmp.push_back(s);
    vis[s] = 1;
    for (auto v : gr[s])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    vector<int> leaders;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            leaders.push_back(i);
            dfs(i);
            // v.push_back(tmp);
            // tmp.clear();
        }
    }

    /* cout<<v.size()-1<<endl;
    for(int i=1;i<v.size();i++){
        cout<<v[0][0]<<" "<<v[i][0]<<endl;
    } */
    int c = leaders.size() - 1;
    cout << c << endl;
    for (int i = 0; i < c; i++)
    {
        cout << leaders[i] << " " << leaders[i + 1] << endl;
    }
}