#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

void dfs(int u)
{

    vis[u] = true;
    for (int v : g[u])
    {
        if (vis[v])
            continue;

        dfs(v);
    }
}

int main()
{
    int n, e;

    cin >> n >> e;
    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    int q;
    cin >> q;
    dfs(q);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            c++;
    }
    cout << c-1 << endl;
}
