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
    ui n;
    size_t m, q;
    fin >> n >> m >> q;
    vector<ui> b(m);
    for (ui& i : b) fin >> i;
    sort(b.begin(), b.end());
    while (q--) {
      ui x;
      fin >> x;
      vector<ui>::iterator it = upper_bound(b.begin(), b.end(), x);
      if (it == b.begin())
        fout << b.front() - 1 << '\n';
      else if (it == b.end())
        fout << n - b.back() << '\n';
      else
        fout << (*it - *prev(it)) / 2 << '\n';
    }
  }
  return 0;
}