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
    size_t n;
    fin >> n;
    map<ui, size_t> cnt;
    for (size_t i = 0; i < n; ++i) {
      ui x;
      fin >> x;
      ++cnt[x];
    }
    size_t maxx = 0;
    for (auto i : cnt) maxx = max(maxx, i.second);
    fout << n - maxx << '\n';
  }
  return 0;
}