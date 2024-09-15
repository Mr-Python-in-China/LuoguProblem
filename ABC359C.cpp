#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  if (tx > ty) swap(tx, ty), swap(sx, sy);

  return 0;
}