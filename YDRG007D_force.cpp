#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
const auto pairHash = [](pair<uli, uli> const &pr) {
  return pr.second + ((pr.first << 32) | (pr.first >> 32));
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  fin >> n >> m;
  vector<vector<uli>> busket(n);
  for (vector<uli> &i : busket) {
    size_t c;
    fin >> c;
    i.resize(c);
    for (uli &j : i) fin >> j;
  }
  unordered_set<pair<uli, uli>, decltype(pairHash)> ans(0, pairHash);
  for (ui b = 0; b < (1 << n); ++b) {
    unordered_set<uli> l, r;
    for (size_t i = 0; i < n; ++i) {
      unordered_set<uli> &s = (b >> i) & 1 ? r : l;
      size_t od = s.size();
      s.insert(busket[i].begin(), busket[i].end());
      size_t nw = s.size();
      if (nw - od != busket[i].size()) goto failed;
    }
    {
      uli xorl = 0, xorr = 0;
      for (uli i : l) xorl ^= i;
      for (uli i : r) xorr ^= i;
      ans.emplace(xorl, xorr);
    }
  failed:;
  }
  while (m--) {
    uli x, y;
    fin >> x >> y;
    fout << (ans.count({x, y}) ? "Yes\n" : "No\n");
  }

  return 0;
}