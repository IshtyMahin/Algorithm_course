#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N = 1e3+5;
int dp[N][N];

int unbounded_knapsack(int n,int s,int val[],int w[]){
    if(n==0 || s==0)return 0;
    

    if(dp[n][s]!=-1)return dp[n][s];
    
    int ch1=0;
    if(w[n-1]<=s)
       ch1 = val[n-1]+unbounded_knapsack(n,s-w[n-1],val,w);

    int ch2 = unbounded_knapsack(n-1,s,val,w);

    return dp[n][s]= max(ch1,ch2);
}

int main(){
     int n,w;
     cin>>n>>w;

     int val[n],weight[n];
     for(int i=0;i<n;i++){
        cin>>val[i];
     }
     for(int i=0;i<n;i++){
        cin>>weight[i];
     }

     memset(dp,-1,sizeof(dp));
     
     cout<<unbounded_knapsack(n,w,val,weight)<<endl;


    int memo[n+1][w+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
           if(i==0 || j==0)memo[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
               memo[i][j]=max(val[i-1]+memo[i-1][j-weight[i-1]],memo[i-1][j]);
            }
            else{
                memo[i][j]=memo[i-1][j];
            }
        }
    }
    cout<<dp[n][w];
}