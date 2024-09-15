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
    int x, y;
    int k;
    fin >> x >> y >> k;
    if (k & 1)
      for (int i = 0; i < k; ++i)
        fout << x << ' ' << y + int(k / 2 - i) << '\n';
    else {
      for (int i = 0; i < k / 2; ++i)
        fout << x << ' ' << y + int(-k / 2 + i) << '\n';
      for (int i = 0; i < k / 2; ++i)
        fout << x << ' ' << y + (int)i + 1 << '\n';
    }
  }
  return 0;
}