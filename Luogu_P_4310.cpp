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
  array<size_t, 32> f{};
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    size_t g = 0;
    for (size_t i = 0; i < 32; ++i)
      if (x & (1 << i)) g = max(g, f[i]);
    ++g;
    for (size_t i = 0; i < 32; ++i)
      if (x & (1 << i)) f[i] = g;
  }
  cout << *max_element(f.begin(), f.end());
  return 0;
}