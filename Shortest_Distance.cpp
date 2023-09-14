#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
/*
   multi source
   1. BFS(No weight) -> V * (V+E) -> V ^3
   2. Dijkstra -> V . (V +  ElogV) -> V^3 log V
   3. Bellman Ford -> V * VE -> V^4

 */
int main()
{
    ll n, e;
    cin >> n >> e;
    ll dis[n + 1][n + 1];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            dis[i][j] = INT_MAX;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if(dis[a][b]>w)
           dis[a][b] = w;
    }

    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if (dis[a][b] == INT_MAX)
            cout << "-1"
                 << endl;
        else cout<<dis[a][b]<<endl;
    }
}