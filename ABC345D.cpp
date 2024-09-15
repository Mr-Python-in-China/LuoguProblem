#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
bool check(vector<vector<bool>>& mp, uc a, uc b, uc c, uc d, bool v) {
  for (uc i = a; i < b; ++i)
    for (uc j = c; j < d; ++j)
      if (mp[i][j] != v) return false;
  return true;
}
void fill(vector<vector<bool>>& mp, uc a, uc b, uc c, uc d, bool val) {
  for (uc i = a; i < b; ++i)
    for (uc j = c; j < d; ++j) mp[i][j] = val;
}
bool f(vector<vector<bool>>& mp, uc x, uc y, vector<pair<uc, uc>>::iterator p,
       vector<pair<uc, uc>>::iterator e) {
  if (p == e) return check(mp, 0, x, 0, y, true);
  if (f(mp, x, y, next(p), e)) return true;
  for (uc i = 0; i < x; ++i)
    for (uc j = 0; j < y; ++j)
      if (!mp[i][j]) {
        if (i + p->first <= x && j + p->second <= y &&
            check(mp, i, i + p->first, j, j + p->second, false)) {
          fill(mp, i, i + p->first, j, j + p->second, true);
          if (f(mp, x, y, next(p), e)) return true;
          fill(mp, i, i + p->first, j, j + p->second, false);
        }
        goto l0;
      }
l0:;
  swap(p->first, p->second);
  for (uc i = 0; i < x; ++i)
    for (uc j = 0; j < y; ++j)
      if (!mp[i][j]) {
        if (i + p->first <= x && j + p->second <= y &&
            check(mp, i, i + p->first, j, j + p->second, false)) {
          fill(mp, i, i + p->first, j, j + p->second, true);
          if (f(mp, x, y, next(p), e)) return true;
          fill(mp, i, i + p->first, j, j + p->second, false);
        }
        goto l1;
      }
l1:;
  swap(p->first, p->second);
  return false;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui x, y;
  cin >> n >> x >> y;
  vector<pair<uc, uc>> a(n);
  for (pair<uc, uc>& i : a) {
    ui p, q;
    cin >> p >> q;
    i.first = p, i.second = q;
  }
  vector<vector<bool>> mp(x, vector<bool>(y));
  sort(a.begin(), a.end());
  do
    if (f(mp, x, y, a.begin(), a.end())) cout << "Yes", exit(0);
  while (next_permutation(a.begin(), a.end()));
  cout << "No";
  return 0;
}