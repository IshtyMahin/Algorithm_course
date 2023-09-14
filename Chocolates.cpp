#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool dp[N][N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        if (sum &1)
        {
            cout << "NO" << endl;
        }
        else
        {
            sum = sum / 2;
            memset(dp, false, sizeof(dp));
            dp[0][0] = true;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (v[i - 1]<=j)
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - v[i - 1]];
                    }
                }
            }

            if (dp[n][sum])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
