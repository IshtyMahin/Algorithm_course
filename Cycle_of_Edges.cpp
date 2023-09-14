#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()

const int N = 1e5 + 5;
int par[N];

int find(int n)
{
    if (par[n] == n)
        return n;
    return par[n] = find(par[n]);
}

int main()
{
    int n, e;
    cin >> n >> e;
    map<pair<int, int>, int> edgeMap;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        if (edgeMap.find({a, b}) == edgeMap.end())
        {
            edgeMap[{a, b}] = w;
        }
    }
    ll x = n-1;
    ll y =  edgeMap.size();

    cout<<x<< " "<<y<<endl;
    return 0;
}
