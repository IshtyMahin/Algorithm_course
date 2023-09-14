#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

const int N = 1e3 + 5;
int dp[N][N];

int unbounded_knapsack(int n, int s, int val[], int w[])
{
    if (n == 0 || s == 0)
        return 0;

    if (dp[n][s] != -1)
        return dp[n][s];

    int ch1 = 0;
    if (w[n - 1] <= s)
        ch1 = val[n - 1] + unbounded_knapsack(n, s - w[n - 1], val, w);

    int ch2 = unbounded_knapsack(n - 1, s, val, w);

    return dp[n][s] = max(ch1, ch2);
}

int main(){
     int n;
     cin>>n;
     int val[n],w[n];

     for(int i=0;i<n;i++){
          cin>>val[i];
          w[i]=i+1;
     }
     memset(dp,-1,sizeof(dp));
     cout<<unbounded_knapsack(n,n,val,w);
}