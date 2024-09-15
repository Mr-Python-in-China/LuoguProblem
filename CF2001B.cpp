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
    ui n;
    fin >> n;
    if (n & 1) {
      for (ui i = 1; i <= n; i += 2) fout << i << ' ';
      for (ui i = n - 1; i > 0; i -= 2) fout << i << ' ';
      fout << '\n';
    } else
      fout << "-1\n";
  }
  return 0;
}