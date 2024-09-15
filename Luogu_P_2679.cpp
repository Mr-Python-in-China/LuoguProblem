#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
ui constexpr P = 1000000007;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  allocator<ui> ui_alloc;
  allocator<vector<ui>> vec_alloc;
  size_t n, m, s;
  string a, b;
  cin >> n >> m >> s >> a >> b;
  vector<vector<ui>> f(n + 1, vector<ui>(m + 1, ui_alloc), vec_alloc);
  for (vector<ui>& i : f) i[0] = 1;
  for (size_t k = 1; k <= s; ++k) {
    vector<vector<ui>> ff(n + 1, vector<ui>(m + 1, ui_alloc), vec_alloc);
    for (size_t i = 1; i <= n; ++i)
      for (size_t j = 1; j <= m; ++j) {
        for (size_t l = 1; l <= i && l <= j && a[i - l] == b[j - l]; ++l)
          ff[i][j] += f[i - l][j - l],
              ff[i][j] >= P ? void(ff[i][j] -= P) : void();
        ff[i][j] += ff[i - 1][j], ff[i][j] >= P ? void(ff[i][j] -= P) : void();
      }
    f.swap(ff);
  }
  cout << f.back().back();
  return 0;
}