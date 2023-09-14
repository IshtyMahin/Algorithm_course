#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18;
class Edge
{
public:
    ll u, v, w;

    Edge(ll a, ll b, ll w)
    {
        this->u = a;
        this->v = b;
        this->w = w;
    }
};
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    ll dis[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin>>s;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] < INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        int a = ed.u;
        int b = ed.v;
        
        int w = ed.w;
        if (dis[a] < INF && dis[a] + w < dis[b])
        {
            cout << "Negaitive Cycle Detected" << endl;
            return 0;
        }
    }

    int q;
    cin>>q;
    while(q--){
        int d;
        cin>>d;
        if(dis[d]==INF){
            cout << "Not Possible\n";
        }
        else 
        cout<<dis[d]<<endl;
    }

    return 0;
}