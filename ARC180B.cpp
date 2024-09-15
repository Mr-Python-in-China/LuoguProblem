#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, l;
  cin >> n >> l;
  vector<size_t> a(n), p(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> a[i];
    p[--a[i]] = i;
  }
  bool flag;
  vector<pair<size_t, size_t>> ans;
  do {
    flag = false;
    for (size_t i = 1; i <= n; ++i)
      for (size_t j = n - 1; ~(j - i); --j)
        if (p[j] < p[j - i] && p[j - i] - p[j] >= l) {
          ans.emplace_back(p[j], p[j - i]);
          swap(a[p[j]], a[p[j - i]]), swap(p[j], p[j - i]);
          flag = true;
          goto cont;
        }
  cont:;
  } while (flag);
  cout << ans.size() << '\n';
  for (pair<size_t, size_t> const &i : ans)
    cout << i.first + 1 << ' ' << i.second + 1 << '\n';
  return 0;
}