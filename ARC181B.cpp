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
    string s, x, y;
    fin >> s >> x >> y;
    int xc1 = count(x.begin(), x.end(), '1'),
        xc0 = count(x.begin(), x.end(), '0'),
        yc1 = count(y.begin(), y.end(), '1'),
        yc0 = count(y.begin(), y.end(), '0');
    int p = xc0 - yc0, q = yc1 - xc1;
    if ((li)p * q < 0) {
      cout << "No\n";
      continue;
    }
    if (p < 0) p *= -1, q *= -1;
    if (q == 0) {
      fout << (p == 0 ? "Yes\n" : "No\n");
      continue;
    }
    int g = __gcd(p, q);
    if (s.size() % (q / g) == 0 &&
        equal(s.begin() + s.size() / (q / g), s.end(), s.begin()))
      fout << "Yes\n";
    else
      fout << "No\n";
  }
  return 0;
}