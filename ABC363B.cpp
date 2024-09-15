#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, p;
  ui t;
  cin >> n >> t >> p;
  vector<ui> l(n);
  for (ui &i : l) cin >> i;
  size_t i = 0;
  for (; count_if(l.begin(), l.end(), [t](ui x) { return x >= t; }) < p; ++i)
    for (ui &j : l) ++j;
  cout << i;
  return 0;
}