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
  vector<int> dl(n), dr(n);
  for (size_t i = 0; i < n; ++i) dl[i] = a[i] - i, dr[i] = a[i] + i;
  vector<int> prmin_dl(n), sfmin_dr(n);
  prmin_dl.front() = dl.front(), sfmin_dr.back() = dr.back();
  for (size_t i = 1; i < n; ++i) prmin_dl[i] = min(prmin_dl[i - 1], dl[i]);
  for (size_t i = n - 2; i < n; --i) sfmin_dr[i] = min(sfmin_dr[i + 1], dr[i]);
  size_t ans = numeric_limits<size_t>::min();
  for (size_t i = 0; i < n; ++i) {
    int ddl = prmin_dl[i], ddr = sfmin_dr[i];
    size_t h = min(ddl + i, ddr - i);
    ans = max(ans, (i + h > n ? n : i + h) - (i < h ? 0 : i - h));
  }
  if (ans & 1 == 0) --ans;
  cout << (ans + 1 >> 1);
  return 0;
}