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
    ui x, y;
    fin >> x >> y;
    ui d = y - x;
    ui l = 1, r = 1e9;
    while (l < r) {
      ui mid = (l + r + 1) / 2;
      uli len = uli(mid - 1) * mid / 2;
      len <= d ? l = mid : r = mid - 1;
    }
    fout << l << '\n';
  }
  return 0;
}