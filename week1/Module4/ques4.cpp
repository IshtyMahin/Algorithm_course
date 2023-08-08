#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
# define vl vector <ll>
#define nl  '\n'
# define all(v) (v).begin() , (v).end()
int main(){
    int n=10000;
    int count = 0;
    for (int i = 1; i < n; i = i * 2)
    {
        for (int j = 1; j * j < n; j += 2)
        {
            count++;
        }
    }

    cout<<count;
}