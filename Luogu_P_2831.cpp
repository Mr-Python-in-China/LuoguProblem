#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    char op;
    cin >> n >> op;
    vector<pair<float, float>> s(n);
    for (pair<float, float> &i : s) cin >> i.first >> i.second;
    vector<ui> funs;
    for (size_t i = 0; i < n; ++i) funs.emplace_back(1 << i);
    for (size_t i = 0; i < n; ++i)
      for (size_t j = i + 1; j < n; ++j) {
        // a=bx+cy,d=ex+fy
        float a = s[i].second, b = s[i].first * s[i].first, c = s[i].first,
              d = s[j].second, e = s[j].first * s[j].first, f = s[j].first;
        float x = (a * f - c * d) / (b * f - c * e),
              y = (a * e - b * d) / (c * e - b * f);
        if (x >= 0) continue;
        funs.emplace_back();
        for (size_t k = 0; k < n; ++k)
          if (abs(s[k].first * s[k].first * x + s[k].first * y - s[k].second) <
              1e-5)
            funs.back() |= 1 << k;
      }
    vector<ui> f(1 << n, numeric_limits<ui>::max() - 1);
    f[0] = 0;
    for (ui status = 0; status < f.size(); ++status)
      for (size_t i = 0; i < funs.size(); ++i)
        f[status | funs[i]] = min(f[status | funs[i]], f[status] + 1);
    cout << f.back() << '\n';
  }
  return 0;
}