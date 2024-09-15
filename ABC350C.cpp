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
  vector<size_t> a(n);
  for (size_t& i : a) cin >> i, --i;
  vector<size_t> b(n);
  for (size_t i = 0; i < n; ++i) b[a[i]] = i;
  vector<pair<size_t, size_t>> ans;
  for (size_t i = 0; i < n; ++i)
    if (a[i] != i) {
      ans.emplace_back(i, b[i]);
      swap(a[i], a[b[i]]);
      b[a[b[i]]] = b[i], b[i] = i;
    }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
  return 0;
}