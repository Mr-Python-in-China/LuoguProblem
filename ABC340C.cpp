#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
uli f(uli x) {
  static unordered_map<uli, uli> mem;
  if (x == 1) return 0;
  if (mem[x]) return mem[x];
  return mem[x] = x + f(x / 2) + f((x + 1) / 2);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli n;
  cin >> n;
  cout << f(n);
  return 0;
}