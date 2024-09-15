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
  cin >> n;
  array<ui, 3> f = {0, 0, 0};
  for (size_t T = 0; T < n; ++T) {
    unsigned short int a, b, c;
    cin >> a >> b >> c;
    f = {max(f[1], f[2]) + a, max(f[0], f[2]) + b, max(f[0], f[1]) + c};
  }
  cout << max({f[0], f[1], f[2]});
  return 0;
}