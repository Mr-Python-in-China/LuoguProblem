#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui f(ui x) {
  static array<ui, 200001> mem = {};
  if (mem[x]) return mem[x];
  if (x == 0) return 0;
  ui& a = mem[x];
  a = f(x - 1);
  while (x) {
    a += x % 10;
    x /= 10;
  }
  return a;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    ui n;
    cin >> n;
    cout << f(n) << '\n';
  }
  return 0;
}