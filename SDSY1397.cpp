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
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; ++i) cin >> a[i] >> b[i];
  auto f = [](vector<int> a) {
    size_t n = a.size();
    sort(a.begin(), a.end());
    return pair<int, int>(a[(n - 1) / 2], a[n / 2]);
  };
  auto g = [n](int x, int y, vector<int> const& a, vector<int> const& b) {
    uli sum = 0;
    for (size_t i = 0; i < n; ++i) sum += abs(a[i] - x) + abs(b[i] - y);
    return sum;
  };
  pair<int, int> x = f(a), y = f(b);
  uli ans = uli(x.second - x.first + 1) * (y.second - y.first + 1);
  for (size_t i = 0; i < n; ++i)
    if (x.first <= a[i] && a[i] <= x.second && y.first <= b[i] &&
        b[i] <= y.second)
      --ans;
  if (ans == 0) {
    cout << min({g(x.first - 1, y.first, a, b), g(x.first, y.first - 1, a, b),
                 g(x.first + 1, y.first, a, b), g(x.first, y.first + 1, a, b)})
         << ' ' << 2;
  } else
    cout << g(x.first, y.first, a, b) << ' ' << ans;
  return 0;
}