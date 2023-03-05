#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const char F[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const ui INF = 0x7fffffff;
using pos = pair<ui, ui>;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ui n, m, k;
    cin >> n >> m >> k;
    vector<vector<ui>> mp(n, vector<ui>(m)), dis(n, vector<ui>(m, -1));
    for (ui i = 0; i < n; i++)
        for (ui j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (!mp[i][j])
                dis[i][j] = INF;
        }
    if (mp[0][0] == INF || mp[n - 1][m - 1] == INF)
    {
        cout << "-1";
        return 0;
    }
    queue<pos> q({pos(0, 0)});
    dis[0][0] = 0;
    while (!q.empty())
    {
        pos p = q.front();
        q.pop();
        for (char i = 0; i < 4; i++)
        {
            pos np(p.first + F[i][0], p.second + F[i][1]);
            if (np.first < n && np.second < m && dis[np.first][np.second] != INF && !~dis[np.first][np.second])
            {
                dis[np.first][np.second] = dis[p.first][p.second] + 1;
                q.push(np);
            }
        }
    }
    cout << int(dis[n - 1][m - 1]);
    return 0;
}