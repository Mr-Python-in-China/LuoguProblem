#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    vector<vector<size_t>> s(n), t(n);
    for (size_t i = 0; i < n; ++i) {
      ui k;
      fin >> k;
      s[i].resize(k);
      for (size_t j = 0; j < k; ++j)
        fin >> s[i][j], t[--s[i][j]].emplace_back(i);
    }
    s.emplace_back(n);
    for (size_t i = 0; i < n; ++i) s[n][i] = i;
    for (vector<size_t>& i : t) {
      i.emplace_back(n);
      sort(i.begin(), i.end(), [&](size_t x, size_t y) {
        return s[x].size() == s[y].size() ? x < y : s[x].size() < s[y].size();
      });
    }
    vector<size_t> fa(n, ~0);
    for (vector<size_t> const& i : t)
      if (!i.empty())
        for (vector<size_t>::const_iterator it = i.cbegin(), jt = next(it);
             jt < i.cend(); ++it, ++jt) {
          if (!~fa[*it])
            fa[*it] = *jt;
          else if (fa[*it] != *jt) {
            fout << "YES\n"
                 << *it + 1 << ' '
                 << (fa[*it]==n?*jt:*jt==n?fa[*it]:![&](size_t x, size_t y) {
                      return !includes(s[y].begin(), s[y].end(), s[x].begin(),
                                       s[x].end());
                    }(*it, fa[*it])
                         ? *jt
                         : fa[*it]) +
                        1
                 << '\n';
            goto end;
          }
        }

    fout << "NO\n";
  end:;
  }
  return 0;
}