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
  bool T;
  ui k;
  size_t m;
  fin >> T >> k >> m;
  vector<ui> a(1u << k);
  for (ui &i : a) fin >> i;
  vector<ui> f = {0, 1};
  for (size_t i = 1; i < (1u << k); ++i) {
    if (a[i - 1] != a[i]) f.emplace_back(f.back());
    ++f.back();
  }
  size_t lst = 0;
  while (m--) {
    char op;
    fin >> op;
    if (op == '1') {
      ui x;
      fin >> x;
      x ^= (T * lst);
      vector<ui> b(1 << k);
      for (size_t i = 0; i < (1u << k); ++i) b[i] = a[i ^ x];
      a = b;
      f = {0, 1};
      for (size_t i = 1; i < (1u << k); ++i) {
        if (a[i - 1] != a[i]) f.emplace_back(f.back());
        ++f.back();
      }
    } else if (op == '2') {
      size_t l, r;
      fin >> l >> r;
      l ^= (T * lst), r ^= (T * lst);
      if (l > r) swap(l, r);
      ++r;
      fout << (lst = lower_bound(f.begin(), f.end(), r) -
                     prev(upper_bound(f.begin(), f.end(), l)))
           << '\n';
    }
  }
  return 0;
}