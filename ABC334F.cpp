#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui dist(ui a, ui b, ui c, ui d) { return (c - a) + (d - b); }
bool cmp(pair<uli, uli> const& a, pair<uli, uli> const& b) {
  return a.first == b.first ? a.second > b.second : a.first < b.first;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<vector<ui>> p(n, vector<ui>(n));
  for (vector<ui>& i : p)
    for (ui& j : i) cin >> j;
  vector<vector<ui>> r(n, vector<ui>(n - 1));
  for (vector<ui>& i : r)
    for (ui& j : i) cin >> j;
  vector<vector<ui>> d(n - 1, vector<ui>(n));
  for (vector<ui>& i : d)
    for (ui& j : i) cin >> j;
  vector<vector<pair<uli, uli>>> f(
      n, vector<pair<uli, uli>>(n, {numeric_limits<uli>::max() / 2, 0}));
  f[0][0] = {0, 0};
  for (size_t i = 1; i < n; ++i) {
    vector<uli> s(i + 1);
    s[i] = 0;
    for (size_t j = i - 1; j < i; --j) s[j] = s[j + 1] + r[0][j];
    for (size_t j = 0; j < i; ++j) {
      uli add = (s[j] + f[0][j].second + p[0][j] - 1) / p[0][j];
      f[0][i] = min(f[0][i],
                    {f[0][j].first + add + dist(0, j, 0, i),
                     (f[0][j].second + add * p[0][j]) - s[j]},
                    cmp);
    }
  }
  for (size_t i = 1; i < n; ++i) {
    vector<uli> s(i + 1);
    s[i] = 0;
    for (size_t j = i - 1; j < i; --j) s[j] = s[j + 1] + d[j][0];
    for (size_t j = 0; j < i; ++j) {
      uli add = (s[j] + f[j][0].second + p[j][0] - 1) / p[j][0];
      f[i][0] = min(f[i][0],
                    {f[j][0].first + add + dist(j, 0, i, 0),
                     (f[j][0].second + add * p[j][0]) - s[j]},
                    cmp);
    }
  }
  for (size_t i = 1; i < n; ++i)
    for (size_t j = 1; j < n; ++j) {
      vector<vector<uli>> s(i + 1, vector<uli>(j + 1));
      s[i][j] = 0;
      for (size_t l = j - 1; l < j; --l) s[i][l] = s[i][l + 1] + r[i][l];
      for (size_t k = i - 1; k < i; --k) s[k][j] = s[k + 1][j] + d[k][j];
      for (size_t k = i - 1; k < i; --k)
        for (size_t l = j - 1; l < j; --l)
          s[k][l] = min(r[k][l] + s[k][l + 1], d[k][l] + s[k + 1][l]);
      for (size_t k = 0; k <= i; ++k)
        for (size_t l = 0; l <= j; ++l) {
          uli add = f[k][l].second > s[k][l] + p[k][l] - 1
                        ? 0
                        : (s[k][l] + p[k][l] - 1 - f[k][l].second) / p[k][l];
          f[i][j] = min(f[i][j],
                        {f[k][l].first + add + dist(k, l, i, j),
                         (f[k][l].second + add * p[k][l]) - s[k][l]},
                        cmp);
        }
    }
  cout << f.back().back().first;
  return 0;
}