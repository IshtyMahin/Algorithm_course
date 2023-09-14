#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }
typedef pair<int, int> pii;

const int N = 1e3 + 10;
vector<string> g;
int vis[N][N];
int level[N][N];
pii parent[N][N];

int n, m;

vector<pii> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;

        q.pop();

        for (auto d : dir)
        {
            int ni, nj;
            ni = i + d.first;
            nj = j + d.second;

            if (isValid(ni, nj) && !vis[ni][nj] && g[ni][nj] != '#')
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    cin >> n ;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
    }

    
    bfs(si, sj);
    if (level[di][dj] == 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES\n";
        cout << level[di][dj] << endl;

        vector<pii> path;
        pii cur = {di, dj};
        while (!(cur.first == si && cur.second == sj))
        {
            path.push_back(cur);
            cur = parent[cur.first][cur.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());
        /* for(auto p :path){
           cout<<p.first<<" "<<p.second<<endl;
        } */
        for (int i = 1; i < path.size(); i++)
        {
            // path[i-1] -> path[i]
            if (path[i - 1].first == path[i].first)
            {
                if (path[i - 1].second == path[i].second - 1)
                {
                    cout << 'R';
                }
                else
                {
                    cout << 'L';
                }
            }
            else
            {
                if (path[i - 1].first == path[i].first - 1)
                {
                    cout << 'D';
                }
                else
                {
                    cout << 'U';
                }
            }
        }
    }
}