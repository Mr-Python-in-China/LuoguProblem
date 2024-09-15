#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using si = short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    vector<vector<si>> a(n);
    for (size_t i = 0; i < n; ++i) {
      a[i].resize(n);
      for (size_t j = i; j < n; ++j) cin >> a[i][j];
    }
    vector<vector<int>> f(n);
    f[0] = {0, a[0][0]};
    sort(f[0].begin(), f[0].end(), greater<int>());
    if (f[0].size() > k) f.resize(k);
    if (n == 1) {
      for (size_t i = 0; i < k; ++i) cout << f.back()[i] << ' ';
      cout << '\n';
      continue;
    }
    f[1] = {0, a[0][0], a[0][1], a[1][1]};
    sort(f[1].begin(), f[1].end(), greater<int>());
    if (f[1].size() > k) f.resize(k);
    for (size_t i = 2; i < n; ++i) {
      for (size_t j = 0; j <= i; ++j) f[i].push_back(a[j][i]);
      sort(f[i].begin(), f[i].end(), greater<int>());
      if (f[i].size() > k) f[i].resize(k);
      for (size_t j = 0; j < i; ++j) {
        size_t mid = f[i].size();
        f[i].insert(f[i].end(), f[j].begin(), f[j].end());
        for (size_t k = mid; k < f[i].size(); ++k) f[i][k] += a[j + 1][i];
        inplace_merge(f[i].begin(), f[i].begin() + mid, f[i].end(),
                      greater<int>());
        if (f[i].size() > k) f[i].resize(k);
      }
    }
    for (size_t i = 0; i < k; ++i) cout << f.back()[i] << ' ';
    cout.put('\n');
  }
  return 0;
}