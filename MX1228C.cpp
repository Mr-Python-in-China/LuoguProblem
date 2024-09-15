#include <bits/extc++.h>

#include <tr2/dynamic_bitset>
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
  fin >> n;
  vector<tr2::dynamic_bitset<>> b(n, tr2::dynamic_bitset<>(n));
  b.reserve(n);
  for (size_t i = 0; i < n; ++i) {
    size_t c;
    fin >> c;
    if (c) b[i].flip();
    while (c--) {
      size_t x;
      fin >> x;
      b[i] &= b[--x];
    }
    b[i].set(i);
  }
  size_t q;
  fin >> q;
  while (q--) {
    size_t c;
    fin >> c;
    vector<size_t> s(c);
    for (size_t &i : s) fin >> i, --i;
    if (s.empty()) {
      fout << "0\n";
      continue;
    }
    tr2::dynamic_bitset<> ans(n);
    for (size_t i : s) ans |= b[i];
    fout << ans.count() << '\n';
  }
  return 0;
}