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
    int m;
    cin >> m;
    vector<int> v1(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
    vector<int> ans(n + m);

    int lp = 0;
    int rp = 0;
    int j = 0;

    while (lp < n && rp < m)
    {
        if (v[lp] >= v1[rp])
        {
            ans[j++] = v[lp++];
        }
        else
        {
            ans[j++] = v1[rp++];
        }
    }

    while (lp < n)
    {
        ans[j++] = v[lp++];
    }
    while (rp < m)
    {
        ans[j++] = v1[rp++];
    }

    for (int i = 0; i < n + m; i++)
    {
        cout << ans[i] << " ";
    }
}
