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
    ui al, ar, bl, br;
    fin >> al >> ar >> bl >> br;
    if (al > bl) swap(al, bl), swap(ar, br);
    if (ar < bl) {
      fout << "1\n";
      continue;
    }
    bitset<101> a, b;
    for (ui i = al; i <= ar; ++i) a.set(i);
    for (ui i = bl; i <= br; ++i) b.set(i);
    ui ans = 0;
    for (ui i = 2; i < 101; ++i)
      if ((a[i - 1] && b[i]) || (b[i - 1] && a[i])) ++ans;
    fout << ans << '\n';
  }
  return 0;
}