#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()


int main(){
          int n;
          cin>>n;
          vector<int>v(n);
          for(int i=0;i<n;i++){
             cin>>v[i];
          }

          int k ;
          cin>>k;

          int  l=0;
          int r=n-1;
          bool flag =false;
          int mid ;

          while(l<r){
             mid = l+(r-l)/2;
             if(v[mid]==k){
                   flag=true;
                   break;
             }
             else if(v[mid]>k){
                r=mid-1;
             }
             else{
                l=mid+1;
             }
          }

          if(flag)cout<<mid;
          else cout<<"Not Found";
}