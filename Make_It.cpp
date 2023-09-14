#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
bool solve(int x, int n)
{
    if (x == n)
    {
        return true;
    }
    if (x > n)
    {
        return false;
    }

    if (dp[x] != -1)
        return dp[x];

    bool op1 = solve(x + 3, n);
    bool op2 = solve(2 * x, n);

    return dp[x] = op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        if (solve(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}