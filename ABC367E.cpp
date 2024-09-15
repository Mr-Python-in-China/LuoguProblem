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
  uli k;
  fin >> n >> k;
  vector<size_t> t(n);
  for (size_t &i : t) fin >> i, --i;
  vector<ui> a(n);
  for (ui &i : a) fin >> i;
  while (k) {
    if (k & 1) {
      vector<ui> b(n);
      for (size_t i = 0; i < n; ++i) b[i] = a[t[i]];
      a = b;
    }
    vector<size_t> s(n);
    for (size_t i = 0; i < n; ++i) s[i] = t[t[i]];
    t = s;
    k >>= 1;
  }
  for (ui i : a) fout << i << ' ';
  return 0;
}