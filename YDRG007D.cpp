#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
bool checkColor(size_t p, bool t, vector<vector<size_t>> const &mp,
                vector<signed char> &color) {
  if (color[p] != -1) return color[p] == t;
  color[p] = t;
  for (size_t i : mp[p])
    if (!checkColor(i, !t, mp, color)) return false;
  return true;
}
pair<uli, uli> getMpXor(size_t p, vector<vector<size_t>> const &mp,
                        vector<signed char> &color,
                        vector<uli> const &busketXor) {
  assert(color[p] == bool(color[p]));
  pair<uli, uli> res = {0, 0};
  (color[p] ? res.second : res.first) ^= busketXor[p];
  color[p] = -1;
  for (size_t i : mp[p])
    if (color[i] != -1) {
      pair<uli, uli> d = getMpXor(i, mp, color, busketXor);
      res.first ^= d.first, res.second ^= d.second;
    }
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  unordered_map<uli, vector<size_t>> typeInBusket;
  vector<uli> busketXor(n);
  for (size_t i = 0; i < n; ++i) {
    size_t c;
    fin >> c;
    while (c--) {
      uli w;
      fin >> w;
      typeInBusket[w].emplace_back(i);
      busketXor[i] ^= w;
    }
  }
  vector<vector<size_t>> mp(n);
  for (auto const &i : typeInBusket) {
    if (i.second.size() > 2) {
      for (size_t j = 0; j < m; ++j) fout << "No\n";
      return 0;
    } else if (i.second.size() == 2)
      mp[i.second[0]].emplace_back(i.second[1]),
          mp[i.second[1]].emplace_back(i.second[0]);
  }
  vector<signed char> color(n, -1);
  for (size_t i = 0; i < n; ++i)
    if (color[i] == -1 && !checkColor(i, 0, mp, color)) {
      for (size_t j = 0; j < m; ++j) fout << "No\n";
      return 0;
    }
  vector<pair<uli, uli>> mpXor;
  for (size_t i = 0; i < n; ++i)
    if (color[i] != -1) mpXor.emplace_back(getMpXor(i, mp, color, busketXor));
  uli lxor = 0, sumxor = 0;
  for (pair<uli, uli> const &i : mpXor)
    lxor ^= i.first, sumxor ^= i.first ^ i.second;
  vector<uli> diff(mpXor.size());
  transform(mpXor.begin(), mpXor.end(), diff.begin(),
            [](pair<uli, uli> const &d) { return d.first ^ d.second; });
  array<uli, numeric_limits<uli>::digits> linearAlgebra = {};
  for (uli x : diff)
    for (size_t i = linearAlgebra.size() - 1; i < linearAlgebra.size(); --i)
      if (x >> i) {
        if (linearAlgebra[i] == 0) {
          linearAlgebra[i] = x;
          break;
        }
        x ^= linearAlgebra[i];
      }
  while (m--) {
    uli x, y;
    fin >> x >> y;
    if ((x ^ y) != sumxor) {
      fout << "No\n";
      continue;
    }
    uli target = lxor ^ x;
    for (size_t i = linearAlgebra.size() - 1; i < linearAlgebra.size(); --i)
      if (target >> i) {
        if (linearAlgebra[i] == 0) {
          fout << "No\n";
          goto failed;
        }
        target ^= linearAlgebra[i];
      }
    fout << "Yes\n";
  failed:;
  }
  return 0;
}