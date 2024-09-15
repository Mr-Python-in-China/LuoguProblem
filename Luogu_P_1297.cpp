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
  {
    uli A, B, C;
    cin >> A >> B >> C;
    cin >> a[0];
    for (size_t i = 1; i < n; ++i) a[i] = (a[i - 1] * A + B) % 100000001;
    for (ui &i : a) i = i % C + 1;
  }
  double f = 0;
  for (size_t i = 1; i < n; ++i) f += 1.0 / max(a[i - 1], a[i]);
  f += 1.0 / max(a.front(), a.back());
  cout << fixed << setprecision(3) << f;
  return 0;
}