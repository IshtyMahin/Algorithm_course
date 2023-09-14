#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int INF = 1e7;

    int n, e;
    cin >> n >> e;

    map<pair<int, int>, int> edgeMap; 

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        if (edgeMap.find({a, b}) == edgeMap.end() || w < edgeMap[{a, b}])
        {
            edgeMap[{a, b}] = w; 
        }
    }

    

    vector<int> dis(n + 1, INF);
    dis[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto [edge, w] : edgeMap)
        {
            int a = edge.first;
            int b = edge.second;
            if (dis[a] < INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (dis[i] == INF ? 30000 : dis[i]) << " ";
    }
    cout << endl;
    return 0;
}
