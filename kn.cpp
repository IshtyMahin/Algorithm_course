#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
const int N = 1e2 + 10;
const int INF = 1e9 + 10;

int visited[N][N];
int level[N][N];
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();
        for (pii d : direc)
        {
            int vi = ui + d.first;
            int vj = uj + d.second;
            if (is_valid(vi, vj) && !visited[vi][vj])
            {
                q.push({vi, vj});
                visited[vi][vj] = true;
                level[vi][vj] = level[ui][uj] + 1;
            }
        }
    }
}
void reset_visit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            level[i][j] = INF;
            visited[i][j] = false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        bfs(si, sj);
        if (!visited[di][dj])
            cout << -1<<endl;
        else
            cout << level[di][dj] << endl;
        reset_visit();
    }
    return 0;
}