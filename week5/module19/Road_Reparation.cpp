#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 1e5 + 5;
vector<pii> v[N];
bool vis[N];

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

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

// V + E logE
void prims(int s,int n)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;

    pq.push(Edge(s, s, 0));
    vector<Edge> edgeList;
    int cnt=0;
    while (!pq.empty())
    {
        auto p = pq.top();
        auto [a, b, w] = p;
        pq.pop();
        if (vis[b])
            continue;

        vis[b] = true;
        cnt++;
        edgeList.push_back(p);

        for (int i = 0; i < v[b].size(); i++)
        {
            auto [c, cw] = v[b][i];
            if (!vis[c])
            {
                pq.push(Edge(b, c, cw));
            }
        }
    }
    edgeList.erase(edgeList.begin());
    long long int sum=0;
    for (auto [a, b, w] : edgeList)
    {
        sum+=(w);
    }

    if(cnt==n)cout<<sum<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}

int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }

    prims(1,n);
}