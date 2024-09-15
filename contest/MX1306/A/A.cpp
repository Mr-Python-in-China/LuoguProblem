#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct pos {
    size_t x, y;
    pos(size_t _x, size_t _y) : x(_x), y(_y) {}
    friend bool operator==(pos const &a, pos const &b) { return a.x == b.x && a.y == b.y; }
    friend bool operator!=(pos const &a, pos const &b) { return !(a == b); }
};
int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    size_t n, m;
    fin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (vector<char> &i : a)
        for (char &j : i)
            fin >> j;
    auto cmp = [&a](pos const &p, pos const &q) { return a[p.x][p.y] < a[q.x][q.y]; };
    vector<vector<bool>> vis(n, vector<bool>(m));
    deque<pos> q({pos(0, 0)});
    while (!q.empty()) {
        pos minx = *min_element(q.begin(), q.end(), cmp);
        fout << a[minx.x][minx.y];
        q.erase(partition(q.begin(), q.end(), [&a, &minx](pos v) { return a[v.x][v.y] == a[minx.x][minx.y]; }), q.end());
        for (size_t t = q.size(); t > 0; --t) {
            pos p = q.front();
            q.pop_front();
            for (pos i : {pos(p.x, p.y + 1), pos(p.x + 1, p.y)})
                if (i.x < n && i.y < m && !vis[i.x][i.y])
                    vis[i.x][i.y] = true, q.push_back(i);
        }
    }
    return 0;
}