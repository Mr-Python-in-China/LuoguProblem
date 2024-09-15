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
  size_t n;
  ui lst;
  fin >> n >> lst;
  ui d = 2e9, c;
  uli ans = 1;
  for (size_t i = 1; i < n; ++i) {
    ui x;
    fin >> x;
    if (x - lst != d) d = x - lst, c = 1;
    ans += ++c;
    lst = x;
  }
  fout << ans;
  return 0;
}