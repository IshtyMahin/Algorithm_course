#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()

const int INF = 1e9+10;
int vis[8][8];
int lev[8][8];

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1'; // Subtract '1' instead of 'a'
}

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int, int>> moves = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int bfs(string source, string dest)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;
    lev[sourceX][sourceY] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first, y = v.second;
        q.pop(); // Don't forget to pop the front element after processing its neighbors

        for (auto move : moves)
        {
            int childX = move.first + x;
            int childY = move.second + y;

            if (!isValid(childX, childY))
                continue;

            if (!vis[childX][childY])
            {
                q.push({childX, childY});
                lev[childX][childY] = lev[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
        if(lev[destX][destY]!=INF){
            break;
        }
    }

    return lev[destX][destY];
}

void reset()
{
    memset(vis, 0, sizeof(vis));
    memset(lev, INF, sizeof(lev));
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl; // Print newline after each test case
    }
    return 0;
}
