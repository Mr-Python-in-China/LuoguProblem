#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<ui> a(n);
  if (n & 1) {
    for (size_t i = 0; i < n; i += 2) a[i] = i + 1;
    for (size_t i = n - 2; i < n; i -= 2) a[i] = n - i;
  } else if (n == 4)
    a = {1, 4, 2, 3};
  else {
    for (size_t i = 0; i < n; i += 2) a[i] = (i < (n >> 1) ? i + 1 : n - i);
    for (size_t i = n - 1; i < n; i -= 2)
      a[i] = (i >= (n >> 1) ? i + 1 : n - i);
  }
  for (ui const& i : a) cout << i << ' ';
  return 0;
}