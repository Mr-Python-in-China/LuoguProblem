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
  uli n;
  fin >> n;
  uli ans = 0;
  for (uli i = 1; i * i <= n; ++i)
    for (uli j = i; j * j * i <= n; ++j) ans += n / i / j - j + 1;
  fout << ans;
  return 0;
}