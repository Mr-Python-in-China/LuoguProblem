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
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  nth_element(a.begin(), a.begin() + n / 2, a.end());
  uli ans = 0;
  for (ui i : a) ans += max(a[n / 2], i) - min(a[n / 2], i);
  cout << ans;
  return 0;
}