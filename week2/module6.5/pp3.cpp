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
const int N = 1e3 + 5;
int adjmat[N][N];
vector<int> adjL[N];
int main()
{
    int n;
    cin >> n;
    int e;
    cin>>e;
    int u,v;
    for (int i = 1; i <= e; i++)
    {
        cin>>u>>v;
        adjL[u].push_back(v);
    }

   

    for (int i = 1; i <= n; i++)
    {
        for (auto v : adjL[i])
        {
            adjmat[i][v]=1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
}