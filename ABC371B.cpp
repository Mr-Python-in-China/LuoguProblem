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
  size_t n, m;
  fin >> n >> m;
  vector<bool> a(n, true);
  while (m--) {
    size_t x;
    char c;
    fin >> x >> c;
    if (a[--x] && c == 'M') {
      fout << "Yes\n";
      a[x] = false;
    } else
      fout << "No\n";
  }
  return 0;
}