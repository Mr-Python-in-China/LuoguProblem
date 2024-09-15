#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct Train {
  size_t a, b;
  ui s, t;
  bool flag;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  ui d;
  fin >> n >> m >> d;
  vector<Train> trains(m);
  for (Train &i : trains)
    fin >> i.a >> i.b >> i.s >> i.t, --i.a, --i.b, i.s += d, i.t += d,
        i.flag = false;
  trains.front().flag = true;
  vector<size_t> t(m);
  iota(t.begin(), t.end(), size_t(0));
  sort(t.begin(), t.end(),
       [&trains](size_t x, size_t y) { return trains[x].s < trains[y].s; });
  vector<vector<size_t>> arriveThere(n);
  for (size_t i = 0; i < m; ++i) arriveThere[trains[i].b].emplace_back(i);
  for (vector<size_t> &i : arriveThere)
    sort(i.begin(), i.end(),
         [&trains](size_t x, size_t y) { return trains[x].t < trains[y].t; });
  vector<size_t> startBefore(m);
  for (size_t i = 0; i < m; ++i)
    startBefore[i] =
        upper_bound(arriveThere[trains[i].a].begin(),
                    arriveThere[trains[i].a].end(), trains[i].s,
                    [&trains](ui x, size_t p) { return trains[p].t > x; }) -
        arriveThere[trains[i].a].begin();
  vector<ui> lstArrive(n);
  vector<size_t> lstProcess(n);
  vector<ui> ans(m);
  for (size_t i : t) {
    for (size_t &j = lstProcess[trains[i].a]; j < startBefore[i]; ++j)
      lstArrive[trains[i].a] =
          max(lstArrive[trains[i].a], trains[arriveThere[trains[i].a][j]].t -
                                          ans[arriveThere[trains[i].a][j]]);
    if (i != 0) ans[i] = min(trains[i].s - lstArrive[trains[i].a], d);
  }
  for_each(next(ans.begin()), ans.end(),
           [&](size_t i) { fout << d - i << ' '; });
  return 0;
}