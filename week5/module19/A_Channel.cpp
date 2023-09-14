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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    bool x = false;
    if (n == m)
    {
        x = 1;
    }
    int st = m, cnt = m;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '+')
        {
            cnt++;
            st++;
            if (cnt >= n)
            {
                x = true;
            }
        }
        else
        {
            cnt--;
        }
    }

    if (st >= n)
    {
        if (x)
        {
            yes;
        }
        else
        {
            cout << "MAYBE" << endl;
        }
    }
    else
    {
        no;
    }
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