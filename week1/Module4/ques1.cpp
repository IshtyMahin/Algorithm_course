#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> v(N);

void merge(int l, int r, int mid)
{
    int l_sz = mid - l + 1;
    int L[l_sz + 1];

    int r_sz = r - mid;
    int R[r_sz + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = v[i];
    }
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = v[i];
    }

    L[l_sz] = R[r_sz] = INT_MIN;
    int lp = 0;
    int rp = 0;

    for (int i = l; i <= r; i++)
    {
        if (L[lp] >= R[rp])
        {
            v[i] = L[lp];
            lp++;
        }
        else
        {
            v[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
