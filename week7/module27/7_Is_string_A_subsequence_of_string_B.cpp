#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a, b;
    cin >> a>>b;

    int n = a.size(), m = b.size();

    //*normal -> O(N)
    int p=0;
    for(char c:b){
        if(c==a[p]){
            p++;
        }
        if(p==a.size()){
            break;
        }
    }
    if(p==a.size()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    if(n==dp[n][m]){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
}