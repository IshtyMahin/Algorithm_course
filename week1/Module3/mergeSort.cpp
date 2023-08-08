#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()


const int N = 1e5 + 10;
int a[N];

void merge(int l, int r, int mid)
{

    int l_sz = mid - l + 1;
    int L[l_sz + 1];

    int r_sz = r - mid;
    int R[r_sz + 1];

    for (int i = l,j=0; i <=mid; i++,j++)
    {
        L[j] = a[i];
    }
    for (int i = mid+1,j=0; i <=r; i++,j++)
    {
         R[j] = a[i];
    }

    L[l_sz] = R[r_sz] = INT_MIN;

   
    int lp = 0;
    int rp = 0;
    for (int i = l; i <= r; i++)
    {
        if(L[lp]>=R[rp]){
            a[i]=L[lp];
            lp++;
        }
        else{
            a[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(int l,int r){

    if(l==r)return;
    int mid  = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,r,mid);
}
int main(){
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
        cin>>a[i];
     }

    //  sort(nums,nums+n);
     
     mergeSort(0,n-1);

     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
     }
}