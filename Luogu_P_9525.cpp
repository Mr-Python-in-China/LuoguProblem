#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct Beaver {
  ui a, b, c;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  vector<Beaver> a(n);
  priority_queue<pair<ui, size_t>> qa, qb, qc;
  for (size_t i = 0; i < n; ++i) {
    fin >> a[i].a >> a[i].b >> a[i].c;
    qa.emplace(a[i].a, i), qb.emplace(a[i].b, i), qc.emplace(a[i].c, i);
  }
  vector<bool> flag(n);
  for (size_t i = 0; i < n; ++i) {
    size_t x = qa.top().second, y = qb.top().second, z = qc.top().second;
    while (flag[x]) {
      qa.pop();
      if (qa.empty()) goto end;
      x = qa.top().second;
    }
    while (flag[y]) {
      qb.pop();
      if (qb.empty()) goto end;
      y = qb.top().second;
    }
    while (flag[z]) {
      qc.pop();
      if (qc.empty()) goto end;
      z = qc.top().second;
    }
    if (a[x].b == a[y].b || a[x].c == a[z].c) flag[x] = true;
    if (a[y].a == a[x].a || a[y].c == a[z].c) flag[y] = true;
    if (a[z].a == a[x].a || a[z].b == a[y].b) flag[z] = true;
    if (!flag[x] && !flag[y] && !flag[z]) {
      fout << a[x].a + a[y].b + a[z].c;
      return 0;
    }
  }
end:;
  fout << "-1";
  return 0;
}