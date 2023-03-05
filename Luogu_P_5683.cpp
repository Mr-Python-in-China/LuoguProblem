#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using Graph = vector<set<ui>>;
void dijkstra(Graph &mp, vector<pair<ui, ui>> &dis, ui s)
{
    using node = pair<ui, ui>;
    vector<bool> vis(mp.size());
    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node(0, s));
    dis[s].first = 0;
    while (!q.empty())
    {
        ui tmp = q.top().second;
        q.pop();
        if (!vis[tmp])
        {
            vis[tmp] = true;
            for (set<ui>::const_reference v : mp[tmp])
                if (dis[v].first > dis[tmp].first + 1)
                    dis[v].first = dis[tmp].first + 1,
                    dis[v].second = tmp,
                    q.push(node(dis[v].first, v));
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ui n, m;
    cin >> n >> m;
    Graph mp(n);
    for (ui i = 0; i < m; i++)
    {
        ui x, y;
        cin >> x >> y;
        x--, y--;
        mp[x].insert(y), mp[y].insert(x);
    }
    vector<pair<ui, ui>> dis(n, {0x7fffffff, -1});
    dijkstra(mp, dis, 0);
    ui s1, t1, s2, t2;
    cin >> s1 >> t1 >> s2 >> t2;
    --s1, --s2;
    if (dis[s1].first > t1 || dis[s2].first > t2)
    {
        cout << "-1";
        return 0;
    }
    set<pair<ui, ui>> edges;
    for (ui i = s1, j = dis[i].second; ~j; i = j, j = dis[i].second)
        edges.insert({min(i, j), max(i, j)}), cout << i + 1 << ',' << j + 1 << ' ';
    for (ui i = s2, j = dis[i].second; ~j; i = j, j = dis[i].second)
        edges.insert({min(i, j), max(i, j)}), cout << i + 1 << ',' << j + 1 << ' ';
    cout << m - edges.size();
    return 0;
}