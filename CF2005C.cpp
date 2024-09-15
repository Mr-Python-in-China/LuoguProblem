#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct funRes {
  size_t cnt, cntGroup;
  unsigned char endWith;
};
funRes fun(vector<unsigned char> const& d, unsigned char st) {
  funRes res = {0, 0, 0};
  for (unsigned char i : d)
    if (i == st) {
      ++res.cnt;
      if (++st == 5) st = 0, ++res.cntGroup;
    }
  res.endWith = st;
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, m;
    fin >> n >> m;
    vector<vector<unsigned char>> s(n);
    for (vector<unsigned char>& i : s) {
      string x;
      fin >> x;
      for (char j : x)
        if (j == 'n')
          i.emplace_back(0);
        else if (j == 'a')
          i.emplace_back(1);
        else if (j == 'r')
          i.emplace_back(2);
        else if (j == 'e')
          i.emplace_back(3);
        else if (j == 'k')
          i.emplace_back(4);
    }
    array<int, 5> f;
    f.fill(numeric_limits<int>::min() / 2);
    f[0] = 0;
    for (vector<unsigned char> const& i : s) {
      array<int, 5> g = f;
      for (size_t j = 0; j < 5; ++j) {
        auto res = fun(i, j);
        g[res.endWith] = max<int>(
            g[res.endWith], f[j] + res.cntGroup * 5 - (i.size() - res.cnt));
      }
      f = move(g);
    }
    int ans = 0;
    for (size_t i = 0; i < 5; ++i) ans = max<int>(ans, f[i] - i);
    fout << ans << '\n';
  }
  return 0;
}