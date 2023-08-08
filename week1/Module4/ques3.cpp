#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k;
    cin >> k;

    int l = 0;
    int r = n - 1;
    int mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == k)
        {
            break;
        }
        else if (v[mid] > k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if ((mid + 1 < n && v[mid + 1] == k) || (mid - 1 >= 0 && v[mid - 1] == k))
    {
        cout << "YES" << endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}