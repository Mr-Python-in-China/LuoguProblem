#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  array<vector<size_t>, size_t(3e5)> c;
  vector<ui> a(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> a[i];
    c[--a[i]].push_back(i);
  }
  while (m--) {
    char op;
    cin >> op;
    if (op == '1') {
      size_t l, r, x;
      cin >> l >> r >> x;
      --l, --x;
      auto lt = lower_bound(c[x].cbegin(), c[x].cend(), l),
           rt = lower_bound(c[x].cbegin(), c[x].cend(), r);
      cout << rt - lt << '\n';
    } else if (op == '2') {
      size_t p;
      cin >> p;
      size_t q = p--;
      if (a[p] == a[q]) continue;
      auto it = lower_bound(c[a[p]].begin(), c[a[p]].end(), p),
           jt = lower_bound(c[a[q]].begin(), c[a[q]].end(), q);
      *it = q, *jt = p;
      swap(a[p], a[q]);
    } else
      throw;
  }
  return 0;
}