#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool target_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n - 1] <= s)
    {
        bool op1 = target_sum(n - 1, a, s - a[n - 1]);
        bool op2 = target_sum(n - 1, a, s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = target_sum(n - 1, a, s);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int s;
        cin >> s;
        s = 1000 - s;
        int a[n];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (target_sum(n, a, s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}