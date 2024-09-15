#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<vector<bool>> a(n, vector<bool>(m));
  for (vector<bool>& i : a)
    for (vector<bool>::reference j : i) {
      char c;
      cin >> c;
      j = c != '*';
    }
  vector<vector<usi>> sl(n, vector<usi>(m));
  for (size_t j = 0; j < m; ++j)
    if (a[0][j]) sl[0][j] = 1;
  for (size_t i = 1; i < n; ++i)
    for (size_t j = 0; j < m; ++j)
      if (a[i][j]) sl[i][j] = sl[i - 1][j] + 1;
  vector<vector<ui>> ans(n, vector<ui>(m));
  for (size_t i = 0; i < n; ++i) {
    stack<size_t> stk;
    for (size_t j = 0; j < m; ++j) {
      while (!stk.empty() && sl[i][stk.top()] >= sl[i][j]) stk.pop();
      ans[i][j] =
          (stk.empty() ? (j + 1) * sl[i][j]
                       : ans[i][stk.top()] + (j - stk.top()) * sl[i][j]);
      stk.push(j);
    }
  }
  uli s = 0;
  for (vector<ui>& i : ans) s += accumulate(i.begin(), i.end(), uli(0));
  cout << s;
  return 0;
}