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
  string a, b, c, d;
  cin >> a >> b >> c >> d;
  for (size_t i = 0; i < n; ++i)
    if (a[i] == c[i] ? b[i] > d[i] : a[i] > c[i])
      swap(a[i], c[i]), swap(b[i], d[i]);
  cout << b;
  return 0;
}