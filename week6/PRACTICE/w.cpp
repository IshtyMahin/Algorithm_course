#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



bool check(ll x,ll s)
{
    if ( x== s)
    {
        return true;
    }
    if(x>s){
        return false;
    }

    bool route1 = check(10* x,s);
    bool route2 = check(20 * x,s);

    return route1 || route2;
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll s;

        cin >> s;

        if (check(1, s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
