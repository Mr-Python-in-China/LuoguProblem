#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
auto findRow(size_t w) {
  return [w](vector<bool> const& s) { return s[w]; };
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  vector<vector<bool>> a(n, vector<bool>(n));
  for (vector<bool>& i : a)
    for (auto j : i) {
      char c;
      fin >> c;
      j = c == '1';
    }
  size_t fp = ~0, ans = numeric_limits<size_t>::max();
  for (size_t i = 0; i < n; ++i) {
    if (!count_if(a.begin(), a.end(), findRow(i))) continue;
    size_t c = count(a[i].begin(), a[i].end(), false);
    if (c < ans) fp = i, ans = c;
  }
  assert(~fp);
  size_t gp = find_if(a.begin(), a.end(), findRow(fp)) - a.begin();
  assert(gp != n);
  vector<bool> garr = a[gp];
  for (size_t j = 0; j < n; ++j)
    if (!a[fp][j])
      for (size_t i = 0; i < n; ++i) a[i][j] = garr[i];
  for (size_t j = 0; j < n; ++j)
    if ((size_t)count_if(a.begin(), a.end(), findRow(j)) < n) ++ans;
  fout << ans;
  return 0;
}