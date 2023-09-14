#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void make(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
}

int find(int n)
{
    if (n == parent[n])
        return n;
    return parent[n] = find(parent[n]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (parentSize[a] < parentSize[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        parentSize[a] += parentSize[b];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    make(n);
    vector<Edge> v;
    vector<Edge> ans;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);
    for (auto val : v)
    {
        auto [a, b, w] = val;
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        Union(a, b);
    }

    if(ans.size()==n-1){
        long long int sum=0;
        for(auto [a,b,w]:ans){
            sum+=w;
        }
        cout<<sum<<endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    
}