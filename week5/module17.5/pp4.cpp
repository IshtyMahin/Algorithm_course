#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
const int INF = 1e9;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // Write your code here.
    const int INF = 1e8;
    vector<int> dis(n + 1, INF);
    dis[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];
            if (dis[a] < INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    return vector<int>(dis.begin() + 1, dis.end());
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, e;
    cin >> n >> e;
    int sr;
    cin >> sr;
    vector<vector<int>> v;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(w);
        v.push_back(tmp);
    }

    vector<int> ans = bellmonFord(n, e, sr, v);

    for (auto i:ans)
    {
       cout << i<<" ";
    }
    cout << endl;
    return 0;
}
