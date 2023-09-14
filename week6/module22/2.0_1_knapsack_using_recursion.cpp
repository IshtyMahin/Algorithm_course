#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v,w;

ll dp[1005][1005];

int knapsack(ll n, ll s)
{
    // base case
    if(n==0 || s==0)return 0;

    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }

    if (w[n - 1] <= s)
    {
        ll op1 = knapsack(n - 1, s - w[n - 1]) + v[n - 1];
        ll op2 = knapsack(n - 1, s);

        return dp[n][s]=max(op1, op2);
    }
    else{
        return dp[n][s]= knapsack(n - 1, s);
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n, target;
        cin >> n >> target;
        v.resize(n);
        w.resize(n);
        
        for (ll i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= target; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << knapsack(n, target) << endl;
    }
}