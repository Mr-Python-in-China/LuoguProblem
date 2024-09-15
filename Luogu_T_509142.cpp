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
  size_t n, m;
  fin >> n >> m;
  vector<size_t> a(n);
  for (size_t& i : a) fin >> i, --i;
  size_t maxv = *max_element(a.begin(), a.end()) + 1;
  vector<vector<size_t>> pf = {vector<size_t>(maxv)};
  for (size_t i : a) {
    pf.emplace_back(pf.back());
    ++pf.back()[i];
  }
  while (m--) {
    size_t l, r, k;
    fin >> l >> r >> k;
    --l, --k;
    for (size_t i = maxv - 1; i < maxv; --i)
      if (pf[l][i] < pf[r][i])
        if (!k--) {
          fout << i + 1 << '\n';
          break;
        }
  }
  return 0;
}