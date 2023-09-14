#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    int a[n], s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    target= 1000-target;
    
    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (dp[i][j] == 1)
                v.push_back(j);
        }
    }
    
    int c=0,c2=0;
    for (int val : v)
    {
        cout<<val<<endl;
    }
    cout << c<< endl;
    return 0;
}