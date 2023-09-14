#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define nl '\n'
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define error cout << -1 << nl
#define all(v) (v).begin(), (v).end()
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }
#define FAST                           \
    ios_base ::sync_with_stdio(false); \
    cin.tie(0);                        \
    cout.tie(0)

void solve(int t)
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n+1);
    double sum=0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum+=v[i];
    }
    double s2 = (n * (n+1))/2;
    double a =(s2)  - (sum);
    
    v[0]=ll(a);
    ll x = k%(n+1);
    // cout<<a<<" "<<x<<endl;
    
    if(x==1){
        for(ll i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
    }
    else if(n==1){
        if(k%2==0){
            cout<<v[1]<<" ";
        }
        else{
            if(v[1]==0){
                cout<<1<<" ";
            }
            else{
                cout << 0 << " ";
            }
        }
    }
    else{
        v.push_back(a);
        for(ll i=n+1-x+1;i<=n;i++){
            cout<<v[i]<<" ";
        }
        for(ll i=0;i<n+1-x;i++){
            cout<<v[i]<<" ";
        }
    }

    cout<<endl;

    

    
}

int main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve(t);
    }
    return 0;
}