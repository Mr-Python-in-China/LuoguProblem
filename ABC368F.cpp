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
  fin >> n;
  vector<ui> a(n);
  for (ui &i : a) {
    ui x;
    fin >> x;
    for (ui j = 2; j * j <= x; ++j)
      while (x % j == 0) x /= j, ++i;
    if (x > 1) ++i;
  }
  ui sum = 0;
  for (ui i : a) sum ^= i;
  fout << (!sum ? "Bruno" : "Anna");
  return 0;
}