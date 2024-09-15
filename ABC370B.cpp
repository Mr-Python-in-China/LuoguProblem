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
  ui n;
  fin >> n;
  vector<vector<size_t>> a(n, vector<size_t>(n));
  for (size_t i = 0; i < n; ++i)
    for (size_t j = 0; j <= i; ++j) {
      fin >> a[i][j];
      a[j][i] = --a[i][j];
    }
  size_t x = 0;
  for (size_t i = 0; i < n; ++i) x = a[x][i];
  fout << x + 1;
  return 0;
}