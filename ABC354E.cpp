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
  vector<pair<ui, ui>> p(n);
  for (pair<ui, ui> &i : p) cin >> i.first >> i.second;
  vector<bool> f(1 << n);
  f[0] = 0;
  for (ui status = 0; status < f.size(); ++status) {
    for (size_t i = 0; i < n; ++i)
      for (size_t j = i + 1; j < n; ++j)
        if ((status & (1 << i)) && (status & (1 << j)) &&
            (p[i].first == p[j].first || p[i].second == p[j].second))
          f[status] = f[status] | !f[status ^ (1 << i) ^ (1 << j)];
  }
  cout << (f.back() ? "Takahashi" : "Aoki");
  return 0;
}