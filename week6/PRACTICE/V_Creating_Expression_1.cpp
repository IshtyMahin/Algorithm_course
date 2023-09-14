#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[21];

bool check(ll sum, ll i,int size,int result)
{
    if (i == size)
    {
        return sum == result;
    }
    bool route1 = check(sum + arr[i], i + 1,size,result);
    bool route2 = check(sum - arr[i], i + 1,size,result);

    return route1 || route2;
}

int main()
{
    ll size, result;

    cin >> size >> result;
    for (ll i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    if (check(arr[0], 1,size,result))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
