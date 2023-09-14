#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9 + 10;
const int N = 100 + 5;
int vis[N][N];
int lev[N][N];

int n, m;

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<pii> moves = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int bfs(int si, int sj, int di, int dj)
{
    queue<pii> q;
    q.push({si, sj});
    vis[si][sj] = 1;
    lev[si][sj] = 0;

    while (!q.empty())
    {

        auto [pi, pj] = q.front();
        
        q.pop();

        for (auto [x, y] : moves)
        {
            int ci = pi + x;
            int cj = pj + y;

            if (!isValid(ci, cj))
                continue;

            if (!vis[ci][cj])
            {
                q.push({ci, cj});
                lev[ci][cj] = lev[pi][pj] + 1;
                vis[ci][cj] = 1;

                if (ci == di && cj == dj)
                {
                    return lev[ci][cj];
                }
            }
        }
    }
    if (vis[di][dj])
        return lev[di][dj];
    else
        return -1;
}

void reset()
{
    memset(vis, 0, sizeof(vis));
    memset(lev, INF, sizeof(lev));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();

        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        cout << bfs(si, sj, di, dj) << endl;
    }
    return 0;
}
