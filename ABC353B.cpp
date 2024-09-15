#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui k;
  cin >> n >> k;
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  ui cnt = 0, x = 0;
  for (ui i : a) {
    if (x + i > k) x = 0, ++cnt;
    x += i;
  }
  x = 0, ++cnt;
  cout << cnt;
  return 0;
}