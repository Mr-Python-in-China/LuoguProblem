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
  uli ans = 0;
  map<ui, ui> c;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    if (x == 0)
      ans += i, ++c[0];
    else {
      for (ui i = 2; i * i <= ui(2e5); ++i)
        while (x % (i * i) == 0) x /= i * i;
      ans += c[x]++ + c[0];
    }
  }
  cout << ans;
  return 0;
}