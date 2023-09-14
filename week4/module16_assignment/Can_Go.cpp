#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
int dis[N];
int n, m;


void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    dis[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto [edge, w] : list_of_edges)
        {
            auto [u, v] = edge;
            if (dis[u] != INF && dis[v] > dis[u] + w)
                dis[v] = dis[u] + w;
        }
    }
}


int main(){
    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list_of_edges.push_back({{u, v}, w});
    }
    int s;
    cin>>s;
    bellman_ford(s);

    int t;
    cin >> t;
    while (t--)
    {
        int d,dw;
        cin>>d>>dw;
        if(dis[d]<=dw){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
     }
}