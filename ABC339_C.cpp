#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  li t = 0, mint = 0;
  for (size_t i = 0; i < n; ++i) {
    li x;
    cin >> x;
    t += x;
    mint = min(mint, t);
  }
  cout << (t -= mint);
  return 0;
}