/*

    * Dijkstra , Ballman ford => single-source shortest path (sssp)
    * Floyd warshall => all pair shortest path

 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()


const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int d[N][N];
int n, m;

void print_matrix(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(d[i][j]==INF)cout<<"X ";
            else
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dist_initialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                d[i][j] = INF;
            }
        }
    }
}



int main()
{

    cin >> n >> m;
    dist_initialize();
    for (int i = 0; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        // d[v][u] = w;AS 
    }

    print_matrix();

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    cout<<"\nAfter Floyd Warshall\n";
    print_matrix();
}