#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;

int w[N], v[N];
int dp[N][N];

int solve(int n, int s)
{
    // Base case
    if (n == 0 || s == 0)
        return 0;

    if (w[n] > s)
        return solve(n - 1, s);


    if (dp[n][s] != -1)
        return dp[n][s];


    int ans1 = solve(n - 1, s);      
    int ans2 = v[n] + solve(n - 1, s - w[n]);
    return dp[n][s] = max(ans1, ans2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << solve(n, s);
}
