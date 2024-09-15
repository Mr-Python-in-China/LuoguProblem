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
  size_t T;
  fin >> T;
  while (T--) {
    size_t n, m;
    fin >> n >> m;
    vector<pair<ui, int>> a(m);
    for (pair<ui, int> &i : a) fin >> i.first >> i.second;
    if (m < 2) {
      fout << "Yes\n";
      continue;
    }
    pair<ui, int> const &x = a[0], y = a[1];
    if ((x.second - y.second) % int(x.first - y.first)) {
      fout << "No\n";
      continue;
    }
    int k = (x.second - y.second) / int(x.first - y.first);
    li b = x.second - li(x.first) * k;
    for (pair<ui, int> &i : a)
      if (li(i.first) * k + b != i.second) {
        fout << "No\n";
        goto failed;
      }
    fout << "Yes\n";
  failed:;
  }
  return 0;
}