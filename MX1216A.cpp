#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui m;
  fin >> n >> m;
  vector<vector<ui>> c(n, vector<ui>(n)), w(n, vector<ui>(n));
  for (auto *i : {&c, &w})
    for (auto &j : *i)
      for (auto &k : j) fin >> k;
  vector<size_t> a(n);
  iota(a.begin(), a.end(), 0);
  vector<size_t> ansp;
  ui ansc = -1;
  do {
    ui sw = 0, sc = 0;
    for (size_t i = 1; i < n; ++i)
      sw += w[a[i - 1]][a[i]], sc += c[a[i - 1]][a[i]];
    if (sw > m) continue;
    if (sc < ansc) ansc = sc, ansp = a;
  } while (next_permutation(a.begin(), a.end()));
  if (ansc == -1)
    fout << "-1";
  else {
    fout << ansc << '\n';
    for (size_t i : ansp) fout << i + 1 << ' ';
  }
  return 0;
}