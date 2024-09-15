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
  for (size_t i = 1; i <= n; ++i)
    if (!a[i - 1])
      for (size_t j = 1; j <= n; ++j)
        if (!a[j - 1] && i != j) {
          cout << "? " << i << ' ' << j << "\n? " << j << ' ' << i << endl;
          ui x, y;
          cin >> x >> y;
          if (x < y)
            a[j - 1] = y;
          else {
            a[i - 1] = x;
            break;
          }
        }
  cout << "! ";
  for (size_t i = 0; i < n; ++i)
    if (a[i])
      cout << a[i] << ' ';
    else
      cout << n << ' ';
  return 0;
}